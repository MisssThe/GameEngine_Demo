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
    void renderWithType(int type)
    {
        CommonUtils::TraverQueue<Shader*>(this->shaderMap.at(type),
             [](Shader* shader)
             {
                 shader->Use();
             }
        );
    }
    //不建议使用（部分测试用）
    void render()
    {
        CommonUtils::TraverMap<int,std::queue<Shader*>*>(this->shaderMap,
           [](int type,std::queue<Shader*>* queue)
           {
                CommonUtils::TraverQueue<Shader*>(queue,
                  [](Shader* shader)
                  {
                        shader->Use();
                  }
              );
           }
        );
//        CommonUtils::TraverQueue<Shader>(this->shaderQueue,
//            [](Shader shader)
//            {
//                shader.Use();
//            }
//         );
    }
private:
    std::unordered_map<int,std::queue<Shader*>*> shaderMap;
private:
    void renderOneShader()
    {
        //调用shader-》绑定顶点数据-》设置texture-》设置额外数据
    }
};


#endif

//GAMEENGINE_MATERIAL_H
