//
// Created by MisThe on 2021/10/28.
// 包含基础图形绘制功能
// 对OpenGL功能进行封装
//

#ifndef GAMEENGINE_ENGINE_H
#define GAMEENGINE_ENGINE_H

#include "EngineSetting.h"
#include "../Components/GameObject.h"
#include "../CommonUtils/CommonUtils.h"
#include "../CommonUtils/GameLog.h"
#include "GraphEngine/GraphEngine.h"
#include "../ShowWindow.h"
#include "../AttriWindow.h"

class Engine
{
public:
    static void Init()
    {
        if (engine == nullptr)
        {
            engine = new Engine();
        }
        EngineSetting::RefreshEngineSetting();
        ShowWindow sw;
        AttriWindow aw;
    }
    static void Run()
    {
        GraphEngine::RunWindows();
    }
private:
    Engine(){}
private:
    static Engine*engine;
};

#endif
//GAMEENGINE_ENGINE_H
