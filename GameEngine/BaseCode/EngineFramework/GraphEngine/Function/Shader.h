//
// Created by MisThe on 2021/11/1.
//

#ifndef GAMEENGINE_SHADER_H
#define GAMEENGINE_SHADER_H

#include <string>
#include <glad.h>
#include <glfw3.h>
#include "../../../CommonUtils/CommonUtils.h"

const std::string UNIFORM_BEGIN = "//------------ UNIFORM START ------------";
const std::string UNIFORM_END   = "//------------ UNIFORM   END ------------";
const int UNIFORM_LENGTH        = UNIFORM_BEGIN.length() + 1;

class Shader
{
public:
    enum ShaderDataType
    {
        INT,FLOAT,UINT,BOOL,
        VEC2,VEC3,VEC4,IVEC2,IVEC3,IVEC4,UVEC2,UVEC3,UVEC4,BVEC2,BVEC3,BVEC4,
        MAT2,MAT3,MAT4,
    };
private:
    int shaderID;
    std::unordered_map<ShaderDataType,std::unordered_map<std::string,std::string>> uniformMap;
public:
    Shader(std::string shaderPath)
    {
    }
    Shader(std::string vertexShaderPath,std::string fragmentShaderPath)
    {
        std::string vCode = CommonUtils::ReadFile(vertexShaderPath);
        std::string fCode = CommonUtils::ReadFile(fragmentShaderPath);
        std::unordered_map<std::string,int> codeMap;
        codeMap.insert(std::pair<std::string,int>(vCode,GL_VERTEX_SHADER));
        codeMap.insert(std::pair<std::string,int>(fCode,GL_FRAGMENT_SHADER));
        this->shaderID = glCreateProgram();
        this->attachShader(codeMap);
//        this->scanProperty(vCode,ShaderType::VERTEX);
//        this->scanProperty(fCode,ShaderType::FRAGMENT);
    }
    Shader(std::string vertexShaderPath,std::string fragmentShaderPath,std::string geometryShaderPath)
    {

    }
    Shader(std::string vertexShaderPath,std::string fragmentShaderPath,std::string tessellationShaderPath,std::string geometryShaderPath)
    {

    }
    ~Shader()
    {
        this->uniformMap.clear();
    }
    void Use()
    {
        glUseProgram(this->shaderID);
    }
//    void setInt(int index,int num);
//    void setFloat(int index,float num)
//    {
//        glUniform1f()
//    }
//    void setTexture(int index);
private:
    void checkCompile(unsigned int shader, bool isProgram = false)
    {
        int success;
        char infoLog[1024];
        if (!isProgram)
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                GameLog::LogError("ShaderCompile", std::string(infoLog));
            }
        }
        else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                GameLog::LogError("ProgramCompile", std::string(infoLog));
            }
        }
    }
    void attachShader(std::unordered_map<std::string,int> codeMap)
    {
        if (this->shaderID < 0 || codeMap.empty())
        {
            GameLog::LogError("CompileShader","shader create failed");
            return;
        }
        CommonUtils::TraverMap<std::string,int>(codeMap,
           [this](std::string codeStr,int shaderType)
           {
               unsigned int shader;
               shader = glCreateShader(shaderType);
               const char* codeChar = codeStr.c_str();
               glShaderSource(shader, 1, &codeChar, NULL);
               glCompileShader(shader);
               checkCompile(shader, false);
               glAttachShader(shaderID,shader);
               glDeleteShader(shader);
           }
        );
        checkCompile(this->shaderID, true);
    }
    void scanProperty(std::string code,ShaderDataType type)
    {
        int firstPos = code.find(UNIFORM_BEGIN);
        int lastPos = code.rfind(UNIFORM_END);
        std::string uniformStr = code.substr(firstPos + UNIFORM_LENGTH, lastPos - firstPos - UNIFORM_LENGTH);
        std::vector<std::string> vec = CommonUtils::Split(uniformStr,";\n");
//        if (uniformMap.find(type) == uniformMap.end())
//        {
//            uniformMap.insert(std::pair<ShaderType,std::unordered_map<std::string,std::string>>(type,std::unordered_map<std::string,std::string>()));
//        }
        std::unordered_map<std::string,std::string>*map = &uniformMap.at(type);
//        CommonUtils::TraverVector<std::string>(vec,
//           [&map](std::string str)
//           {
//                std::vector<std::string> vec = CommonUtils::Split(str," ");
//                map->insert(std::pair<std::string,std::string>(vec[2],vec[1]));
//                glGetUniformLocation(shaderID,)
//           }
//        );
    }
};


#endif
//GAMEENGINE_SHADER_H
