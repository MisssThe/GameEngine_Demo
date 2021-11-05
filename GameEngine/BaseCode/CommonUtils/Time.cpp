//
// Created by 谭地杰 on 2021/10/29.
//

#include "Time.h"

std::string Time::GetTimeStr()
{
    time_t curTime;
    time(&curTime);
    struct tm *nowTime;
    nowTime = localtime(&curTime);
    std::string timeStr = std::to_string(nowTime->tm_year + 1900) + std::string("_" + std::to_string(nowTime->tm_mon + 1)) + std::string("_" + std::to_string(nowTime->tm_mday)) + std::string("   " + std::to_string(nowTime->tm_hour)) + std::string(":" + std::to_string(nowTime->tm_min)) + std::string(":" + std::to_string(nowTime->tm_sec));
    return timeStr;
}
