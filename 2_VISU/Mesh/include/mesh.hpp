#pragma once

#include "../../Shaders/include/MyShader.hpp"
#include <list>
#include <vector>


typedef struct ShapeVertexTex {
    glm::vec3 _position;
    glm::vec3 _normal;
    glm::vec2 _texCoords;

    ShapeVertexTex()
    : _position(), _normal(), _texCoords() {}

    ShapeVertexTex(glm::vec3 pos, glm::vec3 nor, glm::vec2 tex)
    : _position(pos), _normal(nor), _texCoords(tex) {}
    
    ~ShapeVertexTex() = default;
} Vertex;

typedef struct Texture {
    unsigned int _id;
    std::string _type;

    Texture()
    : _id(), _type() {}
    Texture(const unsigned int id,const std::string type)
    : _id(id), _type(type) {}

    ~Texture() = default;
} Texture;



class Mesh {
private :
    std::vector<Vertex> _vertices;
    std::vector<unsigned int> _indices;
    std::vector<glm::mat4> _modelMat;
    unsigned int _vao, _vbo, _ibo;
    Texture _texture;

public :

    Mesh();
    Mesh(const std::vector<Vertex> vertices, const std::vector<unsigned int> indices, const Texture texture)
    : _vertices(vertices), _indices(indices), _texture(texture) {setupMesh();}
    ~Mesh() = default;

    void Draw() const;
    void setupMesh();
};