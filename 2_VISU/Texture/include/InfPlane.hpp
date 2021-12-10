#pragma once

#include <glm/glm.hpp>
#include <GL/glew.h>
#include <iostream>
#include <vector>

class InfPlane {
private :
    std::vector<glm::vec4> _quad;
    glm::vec3 _color;
    glm::mat4 _modelMatrix;

    GLuint _vao;
    GLuint _vbo;
    GLuint _ibo;

public :

    InfPlane();
    ~InfPlane() = default;

    void setModel(glm::mat4 modelmat) {_modelMatrix = modelmat;}

    void render() const;

};