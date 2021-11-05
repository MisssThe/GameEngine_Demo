//
// Created by MisThe on 2021/10/28.
// 包含各种通用功能（静态方法）
//

#ifndef GAMEENGINE_COMMONUTILS_H
#define GAMEENGINE_COMMONUTILS_H


#include <vector>
#include <queue>
#include <json.h>
#include <iostream>
#include "Time.h"
#include "GameLog.h"
#include <fstream>
#include <thread>
#include <unordered_map>

class CommonUtils {
public:
    template<class T> static T SafeCall(std::function<T(int)> func,int n)
    {
        return func(n);
    }
    static void SafeCall(std::function<void()> func)
    {
        func();
    }
    template<class T> static T SafeCall(std::function<T()> func)
    {
        return func();
    }
    template<class T> static void SafeCall(std::function<void(T)> func,T item)
    {
        func(item);
    }

    template<class T,class Q> static void SafeCall(std::function<void(T,Q)> func,T t,Q q)
    {
        func(t,q);
    }
    template<class T> static void TraverQueue(std::queue<T> queue,std::function<void(T)> func)
    {
        int length = queue.size();
        if (length > 0) {
            auto element = queue.front();
            for (int i = 0; i < length; ++i) {
                func(element);
                queue.pop();
                queue.push(element);
            }
        }
    }
    template<class T> static void TraverVector(std::vector<T> vec,std::function<void(T)> func)
    {
        for (auto item:vec)
        {
            SafeCall<T>(func,item);
        }
    }

//    template<class T,class Q,class W> static void TraverVector(std::vector<T> vec,std::function<void(T,Q,W)> func)
//    {
//
//    }

    template<class T,class Q> static void TraverMap(std::unordered_map<T,Q> map,std::function<void(T,Q)> func)
    {
        for (auto item:map)
        {
            SafeCall(func,item.first,item.second);
        }
    }
    static Json::Value ReadJson(std::string filePath)
    {
        std::ifstream jsonFile;
        jsonFile.open(filePath);
        Json::Value root;
        Json::CharReaderBuilder reader;
        JSONCPP_STRING errs;
        Json::parseFromStream(reader, jsonFile, &root, &errs);
        return root;
    }
    static void WriteJson()
    {

    }
    static std::vector<std::string> Split(std::string str,std::string flag)
    {
        std::vector<std::string> result;
        if(str.empty())
        {
            return result;
        }
        int pos = 0;
        int flagLen = flag.length();
        str = str + flag;
        std::string temp;
        do
        {
            pos = str.find(flag);
            temp = str.substr(0,pos);
            if (!temp.empty())
            {
                result.push_back(temp);
            }
            str = str.substr(pos + flagLen,str.size());
        } while (!str.empty());
        return result;
    }
    template<class T> static int ArrayLength(T array)
    {
        int allSize = sizeof(array);
        int oneSize = sizeof(array[0]);
        if (oneSize != 0)
        {
            return allSize/oneSize;
        }
        return 0;
    }
    static int StartThread(std::function<void()> func,bool endless = false)
    {
        //该线程是否需要循环运行
        std::thread* thread;
        int threadId = ++CommonUtils::base_thread_id;
        if (endless)
        {
            thread = new std::thread(
                [](std::function<void()> func,int threadId)
                {
                    while (true)
                    {
                        SafeCall(func);
                        if (CommonUtils::thread_map.at(threadId)->endFlag)
                        {
                            return;
                        }
                    }
                },func,threadId
            );
        }
        else
        {
            thread = new std::thread(
                [](std::function<void()> func)
                {
                    SafeCall(func);
                },func
            );
        }
        Thread* value = new Thread(thread);
        thread_map.insert(std::pair<int,Thread*>(threadId,value));
        return threadId;
    }
    static void StopThread(int threadId)
    {
        thread_map.at(threadId)->endFlag = true;
        thread_map.at(threadId)->thread->join();
        thread_map.erase(threadId);
    }
    static std::string ReadFile(std::string path)
    {
        std::string code;
        std::ifstream file;
        file.exceptions (std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            file.open(path);
            std::stringstream stream;
            stream << file.rdbuf();
            file.close();
            code = stream.str();
        }
        catch (std::ifstream::failure& e)
        {
            GameLog::LogError("ReadFile","file read failed");
        }
        return code;
    }
private:
    struct Thread
    {
    public:
        Thread(std::thread* thread,bool flag = false)
        {
            this->thread = thread;
            this->endFlag = flag;
        }
        ~Thread()
        {
            delete this->thread;
        }
        std::thread* thread;
        bool         endFlag;
    };
    static std::unordered_map<int,Thread*> thread_map;
    static int base_thread_id;
};

#endif

//GAMEENGINE_COMMONUTILS_H
