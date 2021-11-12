//
// Created by MisThe on 2021/11/4.
// 图形渲染必须loop于主线程（可以使用wglMakeCurrent进行context线程切换但开销过高，且部分API必须在主线程使用）
//

#ifndef GAMEENGINE_GRAPHENGINE_H
#define GAMEENGINE_GRAPHENGINE_H


#include "Function/Shader.h"
#include "../EngineSetting.h"
#include "../../Components/GameObject.h"
#include "Function/BaseRender.h"

class GraphEngine
{
public:
private:
    static GraphEngine* engine;
    class EngineWindow
    {
    public:
        EngineWindow(GLFWwindow*window):window(window){}
        ~EngineWindow()
        {
            CommonUtils::TraverQueue<BaseRender*>(this->renderQueue,
                  [](BaseRender* render)
                  {
                     delete render;
                  }
           );
        }
        void render()
        {
            CommonUtils::TraverQueue<BaseRender*>(this->renderQueue,
                 [](BaseRender* render)
                 {
                    render->Use();
                 }
             );
            glfwSwapBuffers(this->window);
        }
    private:
        void addRender(BaseRender* object,int window = 0)
        {
            if (object != nullptr)
            {
                renderQueue.push(object);
            }
        }
    private:
        std::queue<BaseRender*> renderQueue;
        GLFWwindow* window;
        int windowId;
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
    }
    void runWindows()
    {
//        while (true)
//        {
            glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
            CommonUtils::TraverVector<EngineWindow *>(this->windowVec,[](EngineWindow* ew){ew->render();});
            glfwPollEvents();
//        }
    }
};


#endif

//GAMEENGINE_GRAPHENGINE_H
