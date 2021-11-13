#include <vector>
#include "HitBox.hpp"
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <iostream>


struct ShapeVertexTex {
    glm::vec3 _position;
    glm::vec3 _normal;
    glm::vec2 _texCoords;
};


class Shape {

private :
    std::vector<ShapeVertexTex> _vertices;
    GLsizei _nbVertex;
    GLuint _vbo;
    GLuint _vao;
    glm::mat4 _ModelMatrix;

public:

    Shape() = default;
    Shape(const std::vector<ShapeVertexTex> vertices);

    ~Shape();

    inline GLsizei getNbVertex() const {return _nbVertex;}
    inline const ShapeVertexTex* getDataPointer() const {return &_vertices[0];}


    void translate(const float tx, const float ty, const float tz);
    void rotatex(const float alpha);
    void rotatey(const float alpha);
    void rotatez(const float alpha);
    void render() const;

};