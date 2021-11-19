//
// Created by MisThe on 2021/11/18.
// 定义物体基础属性（大小，位置，方向）
//

#ifndef GAMEENGINE_TRANSFORM_H
#define GAMEENGINE_TRANSFORM_H


#include <glm/glm.hpp>
#include "../../Components/Component.h"

class Transform : public Component
{
public:

public:
    void Use()
    {
        //将相关属性传递给Material

    }
private:
    glm::fvec3 position;
    glm::fvec3 rotation;
    glm::fvec4 quaternion;
    glm::fvec3 scale;
};


#endif //GAMEENGINE_TRANSFORM_H
