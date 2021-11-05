//
// Created by MisThe on 2021/10/28.
//

#include "Engine.h"
#include "RenderPipeline.h"

//-----------------------------------  static elements  -------------------------------------
std::queue<GameObject>* Engine::loopQueue = nullptr;
//-----------------------------------  static elements  -------------------------------------

//---------------------------------------------- Graphic功能实现 ----------------------------------------------
void windowSizeCallBack(GLFWwindow* window, int width, int height) {
    //屏幕尺寸改变时回掉
}


Engine::Engine()
{
    this->initGraphic();
    loopQueue = new std::queue<GameObject>();
}

//初始化OpenGL
void Engine::initGraphic()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    this->window = glfwCreateWindow(EngineSetting::GetScreenWidth(), EngineSetting::GetScreenHeight(), "LearnOpenGL", nullptr, nullptr);
    if (this->window == nullptr)
    {
        glfwTerminate();
        GameLog::LogError("Engine Init","init window failed");
    }
    glfwMakeContextCurrent(this->window);
    glfwSetFramebufferSizeCallback(this->window, windowSizeCallBack);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        GameLog::LogError("Engine Init","init glad failed");
    }
}

void Engine::run()
{
    //component use loop
    this->threadVec.push_back(CommonUtils::StartThread(
         []()
        {
//            CommonUtils::TraverQueue<GameObject>(*Engine::GetLoopQueue(),[](GameObject object){object.UseComponents();});
        }, true
    ));
    GLFWwindow* tempWindow = this->window;
    this->threadVec.push_back(CommonUtils::StartThread(
        [&tempWindow]()
        {
//            RenderPipeline::Render(tempWindow);
        }, true
    ));
}
void Engine::pause()
{

}
void Engine::stop()
{
    CommonUtils::TraverVector<int>(this->threadVec,
       [](int id)
       {
           CommonUtils::StopThread(id);
       }
    );
    glfwTerminate();
}


std::queue<GameObject> *Engine::GetLoopQueue()
{
    return loopQueue;
}

void Engine::addObject(GameObject object)
{
    if (loopQueue != nullptr)
    {
//        loopQueue->push(object);
    }
}

Engine::~Engine()
{
    this->stop();
}

//---------------------------------------------- Graphic功能实现 ----------------------------------------------