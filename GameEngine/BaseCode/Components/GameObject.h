//
// Created by MisThe on 2021/10/28.
// 游戏物体对象，所有组件的载体
//

#ifndef GAMEENGINE_GAMEOBJECT_H
#define GAMEENGINE_GAMEOBJECT_H

#include <queue>
#include "Component.h"

class GameObject
{
public:
    GameObject();
    ~GameObject();
    void UseComponents();
//    void AddComponent(Component com);
    Component* GetComponent();
    void deleterComponent();
    void destroy();
    int getComponentLength();
private:
    std::queue<Component> comQueue;
private:

};


#endif

//GAMEENGINE_GAMEOBJECT_H
