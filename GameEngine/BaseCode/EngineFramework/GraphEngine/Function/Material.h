//
// Created by MisThe on 2021/11/1.
// 控制shader的选择使用以及参数传递
//

#ifndef GAMEENGINE_MATERIAL_H
#define GAMEENGINE_MATERIAL_H


#include "../../../CommonUtils/CommonUtils.h"
#include "Shader.h"

struct RenderType
{

};

class Material
{
public:
    Material()
    {

    }
    void addShader(std::string path,int type)
    {
        if (this->shaderMap.find(type) == this->shaderMap.end())
        {
            this->shaderMap.insert(std::pair<int,std::queue<Shader*>*>(type,new std::queue<Shader*>()));
        }
        std::queue<Shader*>* queue = this->shaderMap.at(type);
        queue->push(new Shader(path));
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
    std::unordered_map<int,std::queue<Shader*>*> shaderMap;
};


#endif

//GAMEENGINE_MATERIAL_H
