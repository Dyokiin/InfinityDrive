#include "../include/Shapes.hpp"

const GLuint VERTEX_ATTR_POSITION = 0;
const GLuint VERTEX_ATTR_NORMAL   = 1;
const GLuint VERTEX_ATTR_TEXCOORD = 2;

Shape::Shape(const std::vector<ShapeVertexTex> vertices){
    
    _vertices = vertices;
    _nbVertex = vertices.size();

    glGenBuffers(1, &_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, _nbVertex*sizeof(ShapeVertexTex), &_vertices[0], GL_STATIC_DRAW);
    
    glGenVertexArrays(1, &_vao);
    glBindVertexArray(_vao);
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
    glEnableVertexAttribArray(VERTEX_ATTR_TEXCOORD);
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertexTex), 0);
    glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertexTex), (const GLvoid*)(3*sizeof(GLfloat)));
    glVertexAttribPointer(VERTEX_ATTR_TEXCOORD, 2, GL_FLOAT, GL_FALSE, sizeof(ShapeVertexTex), (const GLvoid*)(6*sizeof(GLfloat)));

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Shape::~Shape(){
    glDeleteBuffers(1, &_vbo);
    glDeleteVertexArrays(1, &_vao);
}

void Shape::translate(const float tx, const float ty, const float tz){
    glm::mat4 transmat = glm::mat4(1, 0, 0, 0,
                                   0, 1, 0, 0,
                                   0, 0, 1, 0,
                                   tx,ty,tz,1);
    _ModelMatrix*=transmat;
}

void Shape::rotatex(const float a){
    glm::mat4 rotatmat = glm::mat4(1,  0,      0,      0,
                                   0,  cos(a), sin(a), 0,
                                   0, -sin(a), cos(a), 0,
                                   0,  0,      0,      1);
    _ModelMatrix*=rotatmat;
}

void Shape::rotatey(const float a){
    glm::mat4 rotatmat = glm::mat4(cos(a), 0, -sin(a), 0,
                                   0,      1,  0,      0,
                                   sin(a), 0,  cos(a), 0,
                                   0,      0,  0,      1);
    _ModelMatrix*=rotatmat;
}

void Shape::rotatez(const float a){
    glm::mat4 rotatmat = glm::mat4(cos(a), sin(a), 0, 0,
                                  -sin(a), cos(a), 0, 0,
                                   0,      0,      1, 0,
                                   0,      0,      0, 1);
    _ModelMatrix*=rotatmat;
}

void Shape::render() const{

    glBindVertexArray(_vao);
    glDrawArrays(GL_TRIANGLES, 0, _nbVertex);
    glBindVertexArray(0);
}