//
// Created by MisThe on 2021/11/1.
// 控制shader的选择使用以及参数传递
//

#ifndef GAMEENGINE_MATERIAL_H
#define GAMEENGINE_MATERIAL_H


#include "../../../CommonUtils/CommonUtils.h"

struct RenderType
{

};

class Material
{
public:
    Material()
    {

    }
    void addShader()
    {

    }
    void renderWithType()
    {
//        CommonUtils::TraverQueue<Shader>(this->shaderQueue,
//             [](Shader shader)
//             {
//                 shader.Use();
//             }
//        );
    }
    void render()
    {
//        CommonUtils::TraverQueue<Shader>(this->shaderQueue,
//            [](Shader shader)
//            {
//                shader.Use();
//            }
//         );
    }
private:
//    std::queue<Shader> shaderQueue;
};


#endif

//GAMEENGINE_MATERIAL_H
