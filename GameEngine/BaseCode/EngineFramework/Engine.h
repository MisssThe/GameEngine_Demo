//
// Created by MisThe on 2021/10/28.
// 包含基础图形绘制功能
// 对OpenGL功能进行封装
//

#ifndef GAMEENGINE_ENGINE_H
#define GAMEENGINE_ENGINE_H

#include <glad.h>
#include <glfw3.h>
#include <queue>

#include "EngineSetting.h"
#include "../Components/GameObject.h"
#include "../CommonUtils/CommonUtils.h"
#include "../CommonUtils/GameLog.h"

typedef struct LoopFunc
{
    int funcId;
    void (*func)();
}LoopFunc;

class Engine
{
public:

private:
    static std::queue<GameObject>*loopQueue;
    GLFWwindow *window;
    std::vector<int> threadVec;
public:
    Engine();
    ~Engine();
    GLFWwindow* createWindow();
    void run();
    void pause();
    void stop();
    void addObject(GameObject obj);
    static std::queue<GameObject>* GetLoopQueue();
private:
    void initGraphic();
};

#endif
//GAMEENGINE_ENGINE_H
