#include <vector>
#include "HitBox.hpp"
#include <GL/gl.h>
#include <glm/glm.hpp>
#include <iostream>


struct ShapeVertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoord;
};


class Shape {

private :
    std::vector<ShapeVertex> _vertices;
    GLsizei _nbVertex;
    GLuint _vbo;

public:

    Shape();
    Shape(const std::vector<ShapeVertex> vertices);

    ~Shape();

    inline GLsizei getNbVertex() const {return _nbVertex;}
    inline const ShapeVertex* getDataPointer() const {return &_vertices[0];}


    void translate(const float tx, const float ty, const float tz);
    void rotate(const float alpha);
    void render() const;

};