//
// Created by MisThe on 2021/11/15.
//

#ifndef GAMEENGINE_ATTRIWINDOW_H
#define GAMEENGINE_ATTRIWINDOW_H

#include "EngineFramework/GraphEngine/GraphEngine.h"
#include "Components/UI/UILayout.h"

class AttriWindow
{
public:
    AttriWindow()
    {
        this->index = GraphEngine::AddWindow(1);
//        UILayout base("text", this->index, true);
//        base.addImage();
        UIImage uiImage(this->index);
    }

private:
    int index;
};
#endif //GAMEENGINE_ATTRIWINDOW_H
