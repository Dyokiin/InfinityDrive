#include "../include/InfPlane.hpp"

InfPlane::InfPlane(){

    _modelMatrix = glm::mat4(1.f);

    _quad = {
        glm::vec4( 0, 0, 0, 1),
        glm::vec4( 500, 0, 0, 1),
        glm::vec4( 0, 0, 500, 1),
        glm::vec4(-500, 0, 0, 1),
        glm::vec4( 0, 0,-500, 1)
    };

    std::vector<int> pIbo = {0,1,2,  0,2,3,  0,3,4,  0,4,1};
    
	glGenBuffers(1, &_vbo);
    glGenVertexArrays(1, &_vao);
    glGenBuffers(1, &_ibo);

    glBindVertexArray(_vao);
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, 20*sizeof(int), &_quad[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, pIbo.size()*sizeof(int), &pIbo[0], GL_STATIC_DRAW);

    const GLuint VERTEX_ATTR_POSITION = 0;
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(int), 0);

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void InfPlane::render() const {

    glBindVertexArray(_vao);
    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

}