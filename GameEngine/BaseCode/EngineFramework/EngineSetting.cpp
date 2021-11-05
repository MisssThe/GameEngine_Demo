//
// Created by 谭地杰 on 2021/10/28.
//

#include "EngineSetting.h"

//----------------------------------   static element   ----------------------------------
int EngineSetting::screen_width = 1920;
int EngineSetting::screen_height = 1080;
std::string EngineSetting::setting_path = "/Users/tandijie/MisThe/GameEngine/BaseCode/SystemDocuments/engine_setting.json";
Color EngineSetting::back_color = Color(1,1,1,1);
//----------------------------------   static element   ----------------------------------


void EngineSetting::RefreshEngineSetting()
{
    Json::Value setting = CommonUtils::ReadJson(setting_path);
    //process property
    screen_width  = setting["screen_width"].asInt();
    screen_height = setting["screen_height"].asInt();
    back_color    = setting["back_color"].asString();
}


int EngineSetting::GetScreenWidth()
{

    return screen_width;
}

int EngineSetting::GetScreenHeight()
{
    return screen_height;
}

void EngineSetting::CheckState()
{
//    if (isReady)
//    {
//        exit(0);
//    }
}

Color EngineSetting::GetBackColor()
{
    return back_color;
}

