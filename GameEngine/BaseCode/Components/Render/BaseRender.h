//
// Created by MisThe on 2021/10/28.
// 基础渲染管线
// 默认渲染队列：不透明物体 -> 透明物体 -> Grab物体(采样屏幕截图)
//

#ifndef GAMEENGINE_BASERENDER_H
#define GAMEENGINE_BASERENDER_H


#include "../Component.h"
#include "../../EngineFramework/GraphEngine/Function/Material.h"

class BaseRender : Component
{
private:
    Material material;
public:
    void Use() override;
private:
    bool fullProperty();
    void render();
};


#endif

//GAMEENGINE_BASERENDER_H
