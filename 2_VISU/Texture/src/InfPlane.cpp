#include "../include/InfPlane.hpp"

InfPlane::InfPlane(){

    _quad = {
        glm::vec3( 1, 1, 0),
        glm::vec3(-1,-1, 0),
        glm::vec3(-1, 1, 0),
        glm::vec3(-1,-1, 0),
        glm::vec3( 1, 1, 0),
        glm::vec3( 1,-1, 0)
    };
    
	glGenBuffers(1, &_vbo);
    glGenVertexArrays(1, &_vao);

    glBindVertexArray(_vao);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, 18*sizeof(int), &_quad[0], GL_STATIC_DRAW);

    const GLuint VERTEX_ATTR_POSITION = 0;
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(int), 0);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void InfPlane::render() const {

    glBindVertexArray(_vao);
    glDrawArrays(GL_TRIANGLES, 0, 18);
    glBindVertexArray(0);

}