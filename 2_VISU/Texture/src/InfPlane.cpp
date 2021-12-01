#include "../include/InfPlane.hpp"

InfPlane::InfPlane(){

    _quad = {
        ShapeVertexTex(glm::vec3(-1,-1,1), glm::vec3(0,1,0), glm::vec2(0)),
        ShapeVertexTex(glm::vec3(-1,-1,1), glm::vec3(0,1,0), glm::vec2(0))
    };
    
    
    
    
    GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	std::vector<ShapeVertexTex> vertices = {ShapeVertexTex(glm::vec3(-0.5,-0.5,0.), glm::vec3(1.,0.,0.), glm::vec2(0)),
											ShapeVertexTex(glm::vec3( 0.5,-0.5,0.), glm::vec3(0.,1.,0.), glm::vec2(0)),
											ShapeVertexTex(glm::vec3( 0. , 0.5,0.), glm::vec3(0.,0.,1.), glm::vec2(0))};
    glBufferData(GL_ARRAY_BUFFER, 3*sizeof(ShapeVertexTex), &vertices[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    const GLuint VERTEX_ATTR_POSITION = 3;
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    const GLuint VERTEX_ATTR_COLOR = 8;
    glEnableVertexAttribArray(VERTEX_ATTR_COLOR);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertexTex), 0);
    glVertexAttribPointer(VERTEX_ATTR_COLOR, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertexTex), (const GLvoid*)(sizeof(glm::vec3)));   
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}