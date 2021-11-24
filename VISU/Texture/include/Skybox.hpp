#pragma once 

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <vector>
#include <string>
#include "../include/Image.hpp"
#include "../../Object/include/Object.hpp"


class Skybox {
private :
    GLuint _skyVAO;
    GLuint _skyVBO;
    GLuint _skyEBO;
    GLuint _texture;
    std::vector<std::string> _faces;

public:
    Skybox();
    ~Skybox();

    void display() const;
};