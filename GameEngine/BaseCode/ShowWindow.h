//
// Created by MisThe on 2021/11/15.
//

#ifndef GAMEENGINE_SHOWWINDOW_H
#define GAMEENGINE_SHOWWINDOW_H


#include "EngineFramework/GraphEngine/GraphEngine.h"
#include "Components/UI/ExtendUI/UIImage.h"

class ShowWindow
{
public:
    ShowWindow()
    {
        this->index = GraphEngine::AddWindow(0);
        UIImage uiImage(this->index);

    }
    int index;
};


#endif //GAMEENGINE_SHOWWINDOW_H
