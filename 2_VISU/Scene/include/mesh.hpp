#pragma once

#include "../../Shaders/include/MyShader.hpp"
#include "../../Texture/include/stb_image.h"
#include <list>
#include <vector>
#include <iostream>

/// \struct Vertex
/// \brief struct representing a Vertex
typedef struct ShapeVertexTex {
    glm::vec3 _position;    /*!< Position of the Vertex */
    glm::vec3 _normal;      /*!< Normal of the Vertex */
    glm::vec2 _texCoords;   /*!< Texture coordinates of the Vertex */

    /// \brief Default Constructor
    ShapeVertexTex()
    : _position(), _normal(), _texCoords() {}

    /// \brief Constructor
    /// \param pos : Position
    /// \param nor : Normal
    /// \param tex : texture coordinates
    ShapeVertexTex(glm::vec3 pos, glm::vec3 nor, glm::vec2 tex)
    : _position(pos), _normal(nor), _texCoords(tex) {}
    
    /// \brief Default destructor
    ~ShapeVertexTex() = default;
} Vertex;

/// \struct Texture
/// \brief struct allowing me to stock and use textures
typedef struct Texture {
    unsigned int _id;   /*!< Texture id */
    std::string _type;  /*!< texture type */

    /// \brief Default constructor
    Texture()
    : _id(), _type() {}
    /// \brief Constructor
    /// \param id : texture id
    /// \param type : texture type
    Texture(const unsigned int id,const std::string type)
    : _id(id), _type(type) {}

    /// \brief Default Destructor
    ~Texture() = default;
} Texture;

/// \class Mesh
/// \brief class defining a Mesh to render
class Mesh {
private :
    std::vector<Vertex> _vertices;      /*!< vector of all Vertices of the mesh */
    std::vector<unsigned int> _indices; /*!< vector of the indices of vertices */
    unsigned int _vao, _vbo, _ibo;      /*!< GL : vao, vbo and ibo of the mesh */
    Texture _texture;                   /*!< texture of the mesh */

public :

    /// \brief default constructor
    Mesh();
    /// \brief Constructor
    /// \param vertices : vector of vertices
    /// \param indices : vector of indices
    /// \param texture : assigned texture
    Mesh(const std::vector<Vertex> vertices, const std::vector<unsigned int> indices, const Texture texture)
    : _vertices(vertices), _indices(indices), _texture(texture) {setupMesh();}
    /// \brief Defautl destructor
    ~Mesh() = default;

    /// \brief Draw the Mesh
    void Draw() const;
    /// \brief Setup the mesh outside of the constructor
    void setupMesh();
};



/**** Textured Plane be like :  *******
              p1          p3
                °--------°
                |      / |
                |    /   |
                |  /     |
                °--------°
              p4          p2
**************************************/

/// \brief Return the Mesh of a 3D plane with associated texture
/// \param p1 : one corner of the plane
/// \param p2 : opposed corner
/// \param pathToTex : relative Path to the associated texture
const Mesh texturedPlane(const glm::vec3 p1, const glm::vec3 p2, std::string pathToText);
/// \brief Return the Mesh of a 2D plane with associated texture
/// \param p1 : one corner of the plane
/// \param p2 : opposed corner
/// \param text : SDL surface from SDL_ttf to texture
const Mesh texturedPlane(const glm::vec2 p1, const glm::vec2 p2, SDL_Surface* text);