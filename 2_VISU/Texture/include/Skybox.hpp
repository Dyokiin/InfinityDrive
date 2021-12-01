#pragma once 

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include "Image.hpp"
#include "stb_image.h"
#include "../../../1_CORE/Scene/include/Scene.hpp"


class Skybox {
private :
    unsigned int _skyVAO;
    unsigned int _skyVBO;
    unsigned int _skyEBO;
    unsigned int _texture;
    unsigned int _uTexture;
    std::vector<std::string> _faces;

public:
    Skybox();
    ~Skybox();

    void display() const;
};