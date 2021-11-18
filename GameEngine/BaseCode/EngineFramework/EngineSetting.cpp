//
// Created by 谭地杰 on 2021/10/28.
//

#include "EngineSetting.h"

//----------------------------------   static element   ----------------------------------
std::vector<float> EngineSetting::screen_width = std::vector<float>();
std::vector<float> EngineSetting::screen_height = std::vector<float>();
std::string EngineSetting::setting_path = "/Users/tandijie/GameEngine_Demo/GameEngine/BaseCode/SystemDocuments/engine_setting.json";
std::vector<Color> EngineSetting::back_color = std::vector<Color>();
int EngineSetting::setNum_window = 0;
int EngineSetting::setNum_shader = 0;
std::vector<std::vector<ShaderPath>*> EngineSetting::shader_path;
//----------------------------------   static element   ----------------------------------


void EngineSetting::RefreshEngineSetting()
{
    Json::Value setting = CommonUtils::ReadJson(setting_path);
    //process property
    Json::Value window_set = setting["window_set"];
    Json::Value shader_set = setting["shader_path"];
    setNum_window = window_set.size();
    setNum_shader = shader_set.size();
    Json::Value tempSet;
    for (int i = 0; i < setNum_window; ++i) {
        tempSet = window_set["set_" + std::to_string(i)];
        screen_width.push_back(tempSet["screen_width"].asFloat());
        screen_height.push_back(tempSet["screen_height"].asFloat());
        back_color.push_back(Color(tempSet["back_color"].asString()));
    }
    Json::Value::Members names;
    std::vector<std::string> pathVec;

    for (int i = 0; i < setNum_shader; ++i) {
        tempSet = shader_set["path_"+ std::to_string(i)];
        shader_path.push_back(new std::vector<ShaderPath>());
        names = tempSet.getMemberNames();
        for (auto name : names) {
            {
                std::vector<std::string> tempVec;
                pathVec.swap(tempVec);
            }
            for (int j = 0; j < tempSet[name].size(); ++j) {
                pathVec.push_back(tempSet[name][j].asString());
            }
            shader_path[i]->push_back(ShaderPath(name,pathVec));
        }
    }
}


float EngineSetting::GetScreenWidth(int index)
{
    if (index < setNum_window)
    {
        return screen_width[index];
    }
    return 0;
}

float EngineSetting::GetScreenHeight(int index)
{
    if (index < setNum_window)
    {
        return screen_height[index];
    }
    return 0;
}

void EngineSetting::CheckState()
{
//    if (isReady)
//    {
//        exit(0);
//    }
}

Color EngineSetting::GetBackColor(int index)
{
    if (index < setNum_window)
    {
        return back_color[index];
    }
    return Color();
}

std::vector<ShaderPath>* EngineSetting::GetShaders(int index) {
    if (index < setNum_shader)
        return shader_path[index];
    return new std::vector<ShaderPath>();
}

