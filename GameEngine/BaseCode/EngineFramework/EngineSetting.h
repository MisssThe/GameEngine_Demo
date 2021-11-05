//
// Created by MisThe on 2021/10/28.
//

#ifndef GAMEENGINE_ENGINESETTING_H
#define GAMEENGINE_ENGINESETTING_H

#include <stdlib.h>
#include "../CommonUtils/CommonUtils.h"

//-------structure--------
struct Color
{
public:
    explicit Color(float r = 0,float g = 0,float b = 0,float a = 0):r(r),g(g),b(b),a(a){}
    Color(std::string color)
    {
        std::vector<std::string> vec = CommonUtils::Split(color,",");
        float colorNum[4] = {0};
        int len1,len2;
        len1 = vec.size();
        len2 = CommonUtils::ArrayLength(colorNum);
        for (int i = 0; i < len1 && i < len2; ++i)
        {
            colorNum[i] = std::stof(vec[i]);
        }
        this->r = colorNum[0];
        this->g = colorNum[1];
        this->b = colorNum[2];
        this->a = colorNum[3];
    }
    float r,g,b,a;
};
//-------structure--------

class EngineSetting
{
public:
    static void RefreshEngineSetting();
    static int GetScreenWidth();
    static int GetScreenHeight();
    static Color GetBackColor();
    static void CheckState();
private:
    static int screen_width;
    static int screen_height;
    static bool is_ready;
    static std::string setting_path;
    static Color back_color;
};

#endif

//GAMEENGINE_ENGINESETTING_H
