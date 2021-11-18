//
// Created by 谭地杰 on 2021/10/28.
//

#include "GameObject.h"

GameObject::GameObject()
{

}

//游戏物体运行自身所有组件
void GameObject::UseComponents()
{
//    for (int i = 0; i < this->componentList.size(); ++i)
//    {
//        this->componentList[i].Use();
//    }
}

//void GameObject::AddComponent(Component com)
//{
//
//}

void GameObject::deleterComponent()
{

}

Component* GameObject::GetComponent()
{
    return nullptr;
}

//deleterComponentint GameObject::getComponentLength()
//{
//    return this->componentList.size();
//}

GameObject::~GameObject()
{

}

void GameObject::destroy()
{

}
