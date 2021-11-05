//
// Created by MisThe on 2021/11/4.
// 基础渲染管线
// 默认渲染队列：不透明物体 -> 透明物体 -> Grab物体(采样屏幕截图)
//

#ifndef GAMEENGINE_RENDERPIPELINE_H
#define GAMEENGINE_RENDERPIPELINE_H

#include <queue>
#include "../Components/Render/BaseRender.h"
#include "../Components/GameObject.h"
#include "EngineSetting.h"

class RenderPipeline
{
//private:
//    static RenderPipeline* pipeline;
////    std::queue<> renderQueue;
//public:
//    static RenderPipeline* GetPipeline();
//    static void Render(GLFWwindow* window);
//    static void AddRender(BaseRender render);
//    static void AddRender(GameObject object);
//    ~RenderPipeline();
//private:
//    RenderPipeline();
//    void render(GLFWwindow* window);
//    void renderOnce(GLFWwindow*window);
//    void addRender();
};

#endif
//GAMEENGINE_RENDERPIPELINE_H
