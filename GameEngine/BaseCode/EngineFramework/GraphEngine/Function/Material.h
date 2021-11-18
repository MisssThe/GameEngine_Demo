//
// Created by MisThe on 2021/11/1.
// 控制shader的选择使用以及参数传递（材质即数据，shader即指令）
//

#ifndef GAMEENGINE_MATERIAL_H
#define GAMEENGINE_MATERIAL_H

#include "Shader.h"
#include "Model.h"
#include "../../EventCenter.h"
#include "../ShaderController.h"

class Material
{
public:
    unsigned int VAO,shaderProgram;
    //测试用
    Material(int index)
    {
        EventCenter::UseEvent("UseWindow",index);
//        const char *vertexShaderSource = "#version 330 core\n"
//                                         "layout (location = 0) in vec3 aPos;\n"
//                                         "void main()\n"
//                                         "{\n"
//                                         "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//                                         "}\0";
//        const char *fragmentShaderSource;
//        if (index == 0)
//        {
//            fragmentShaderSource= "#version 330 core\n"
//                                  "out vec4 FragColor;\n"
//                                  "void main()\n"
//                                  "{\n"
//                                  "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//                                  "}\n\0";
//        }
//        else
//        {
//            fragmentShaderSource= "#version 330 core\n"
//                                  "out vec4 FragColor;\n"
//                                  "void main()\n"
//                                  "{\n"
//                                  "   FragColor = vec4(1.0f, 1.0f, 0.2f, 1.0f);\n"
//                                  "}\n\0";
//        }
//
//        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//        glCompileShader(vertexShader);
//        int success;
//        char infoLog[512];
//        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//        if (!success)
//        {
//            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//        }
//        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//        glCompileShader(fragmentShader);
//        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//        if (!success)
//        {
//            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//        }
//        shaderProgram = glCreateProgram();
//        glAttachShader(shaderProgram, vertexShader);
//        glAttachShader(shaderProgram, fragmentShader);
//        glLinkProgram(shaderProgram);
//        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        this->shader = ShaderController::GetShader(index,"UI");
        float vertices[] = {
                0.5f,  0.5f, 0.0f,  // top right
                0.5f, -0.5f, 0.0f,  // bottom right
                -0.5f, -0.5f, 0.0f,  // bottom left
                -0.5f,  0.5f, 0.0f   // top left
        };
        unsigned int indices[] = {  // note that we start from 0!
                0, 1, 3,  // first Triangle
                1, 2, 3   // second Triangle
        };
        unsigned int VBO, EBO;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
//        shader = ShaderController::GetShader("UI");
        this->type = 0;
    }
    Material(Shader*shader,int shaderType,Mesh*mesh)
    {
        if (shader != nullptr && mesh != nullptr)
        {
            this->shader = shader;
            this->type = shaderType;
            this->mesh = mesh;
        }
    }
    void render()
    {
        this->shader->Use();
//        glUseProgram(shaderProgram);
//        this->mesh->Use();
        glBindVertexArray(this->VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
    int getType()
    {
        return this->type;
    }
private:
    int type;
    Shader* shader;     //一个材质只能包含一个shader，一个物体可以包含多个材质
    Mesh* mesh;       //顶点数据
    std::map<std::string,int> textureMap;
    std::map<std::string,float> dataMap;
private:

};

#endif

//GAMEENGINE_MATERIAL_H
