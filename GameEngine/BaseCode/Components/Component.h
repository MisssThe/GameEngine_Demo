//
// Created by 谭地杰 on 2021/10/28.
//

#ifndef GAMEENGINE_COMPONENT_H
#define GAMEENGINE_COMPONENT_H

class Component
{
public:
    virtual void Use() = 0;
    virtual ~Component()
    {

    }
};

#endif //GAMEENGINE_COMPONENT_H
