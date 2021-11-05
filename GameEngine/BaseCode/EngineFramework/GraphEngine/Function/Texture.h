//
// Created by MisThe on 2021/11/4.
//

#ifndef GAMEENGINE_TEXTURE_H
#define GAMEENGINE_TEXTURE_H

#include <glad.h>
#include <stb_image.h>
#include "../../../CommonUtils/GameLog.h"


class Texture
{
public:
    unsigned int texture;
    enum WrapType
    {
        REPEAT = GL_REPEAT,
        MIRROR_REPEAT = GL_MIRRORED_REPEAT,
        EDGE = GL_CLAMP_TO_EDGE,
        BORDER = GL_CLAMP_TO_BORDER
    };
    enum FilterType
    {
        NEAR_NEAR = GL_NEAREST_MIPMAP_NEAREST,
        LINER_NEAR = GL_LINEAR_MIPMAP_NEAREST,
        NEAR_LINER = GL_NEAREST_MIPMAP_LINEAR,
        LINER_LINER = GL_LINEAR_MIPMAP_LINEAR
    };
public:
    Texture(std::string texturePath)
    {
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        //----------------------- Texture Parameter -----------------------
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        //----------------------- Texture Parameter -----------------------

        int width, height, nrChannels;
        stbi_set_flip_vertically_on_load(true);
        unsigned char *data = stbi_load(texturePath.c_str(), &width, &height, &nrChannels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            GameLog::LogError("LoadTexture","Load Texture Failed");
        }
        stbi_image_free(data);
    }
    void setWrapType()
    {

    }
    void setFilterType()
    {

    }
    void useTexture()
    {
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, this->texture);
    }
};


#endif

//GAMEENGINE_TEXTURE_H
