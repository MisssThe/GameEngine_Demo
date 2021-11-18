//
// Created by MisThe on 2021/11/15.
// 负责渲染路径设置
// 实现gpu阶段剔除
//

#ifndef GAMEENGINE_BASEPIPELINE_H
#define GAMEENGINE_BASEPIPELINE_H


#include "../../CommonUtils/CommonUtils.h"
#include "Function/Material.h"
#include "../EventCenter.h"

class BasePipeline
{
public:
    enum RenderType
    {
        Opaque,Transparent,End
    };

    static void AddRender(int index,Material*material)
    {
        if (materialVec.size() > index) {
            if (material != nullptr) {
                std::vector<std::queue<Material*>*>* vec = materialVec[index];
                int type = material->getType();
                if (vec->size() > type && type >= 0) {
                  vec->at(type)->push(material);
                } else
                {
                    GameLog::LogError("AddRenderInPipeline","try to add a wrong material");
                }
            }
        }
        else
        {
            AddRenderQueue();
            AddRender(index,material);
        }
    }
    static void Render(int index)
    {
        if (index < materialVec.size()) {
            CommonUtils::TraverVector<std::queue<Material*>*>(materialVec[0],[](std::queue<Material*>* queue)
            {
                CommonUtils::TraverQueue<Material*>(queue,[](Material*material)
                {
                    material->render();
                });
            });
        }
    }
    static void clearPipeline()
    {

    }
    ~BasePipeline()
    {
        clearPipeline();
    }
//    void renderLoop()
//    {
//
//    }
private:
    static std::vector<std::vector<std::queue<Material*>*>*> materialVec;
private:
    static void AddRenderQueue()
    {
        std::vector<std::queue<Material*>*>* tempMaterialVec = new std::vector<std::queue<Material*>*>();
        for (int i = 0; i < RenderType::End; ++i) {
            tempMaterialVec->push_back(new std::queue<Material*>());
        }
        materialVec.push_back(tempMaterialVec);
    }
};


#endif //GAMEENGINE_BASEPIPELINE_H
