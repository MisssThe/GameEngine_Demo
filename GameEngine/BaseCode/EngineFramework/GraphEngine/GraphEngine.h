//
// Created by MisThe on 2021/11/4.
// 图形渲染必须loop于主线程
//

#ifndef GAMEENGINE_GRAPHENGINE_H
#define GAMEENGINE_GRAPHENGINE_H


#include "Function/Shader.h"
#include "../EngineSetting.h"

class GraphEngine
{
public:
private:
    static GraphEngine* engine;
    struct EngineWindow
    {
    public:
        EngineWindow(GLFWwindow*window):window(window){}
        ~EngineWindow()
        {
            CommonUtils::StopThread(threadId);
        }
    public:
        GLFWwindow* window;
        int threadId;
    };
    std::vector<EngineWindow*> windowVec;
public:
    ~GraphEngine()
    {

    }
    static GraphEngine* GetEngine()
    {
        engine = (engine == nullptr)?(new GraphEngine()):engine;
        return engine;
    }
    static void AddWindow()
    {
        GetEngine()->addWindow();
    }
    static void RunWindows()
    {
        GetEngine()->runWindows();
    }
private:
    GraphEngine()
    {
        init();
    }
    void init()
    {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    }
    void addWindow()
    {
        GLFWwindow* window = glfwCreateWindow(EngineSetting::GetScreenWidth(), EngineSetting::GetScreenHeight(), "LearnOpenGL", nullptr, nullptr);
        if (window == nullptr)
        {
            glfwTerminate();
            GameLog::LogError("Engine Init","init window failed");
        }
        glfwMakeContextCurrent(window);
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            GameLog::LogError("Engine Init","init glad failed");
        }
        windowVec.push_back(new EngineWindow(window));
        while (true)
        {
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(windowVec[0]->window);
            glfwPollEvents();
        }
    }
    void runWindows()
    {
        CommonUtils::TraverVector<EngineWindow*>(this->windowVec,
         [](EngineWindow* window)
          {
            window->threadId = CommonUtils::StartThread(
                [&window]()
                {
                    glfwSwapBuffers(window->window);
                }, true
            );
          }
        );
    }
};


#endif
//GAMEENGINE_GRAPHENGINE_H
