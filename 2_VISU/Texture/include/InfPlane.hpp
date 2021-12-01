#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <iostream>
#include <vector>
#include "../../Object/include/Object.hpp"

class InfPlane {
private :
    std::vector<ShapeVertexTex> _quad;
    glm::vec3 _color;

    GLuint _vao;
    GLuint _vbo;

public :

    InfPlane();
    ~InfPlane() = default;

    void const render();

};