#pragma once

#include <SDL2/SDL.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <iostream>
#include <vector>

#include "mesh.hpp"

/// \class Model
/// \brief Class defining a model, with its material caracteristics
class Model {
private :
    std::vector<Mesh> _mesh;    /*!< Mesh of the model */
    std::string _textPath;      /*!< Path to the texture */
    glm::vec3 _Kd;              /*!< gloom of the material */
    glm::vec3 _Ks;              /*!< specular of the material */

public :

    /// \brief Constructor [WIP]
    /// \param path : relative path to file to load
    Model(char * path) {loadModel(path);}
    /// \brief Constructor
    /// \param mesh : construct a model frome this mesh with default material
    Model(std::vector<Mesh> mesh)
    : _mesh(mesh), _Kd(0.01), _Ks(0.01) {}
    /// \brief Constructor
    /// \param path : file to load
    /// \param Ks : specular of the material
    /// \param Kd : gloom od the material
    Model(char * path, glm::vec3 Ks, glm::vec3 Kd)
    : _Kd(Kd), _Ks(Ks) {loadModel(path);}
    /// \brief Destructor
    ~Model() = default;

    /// \brief Load a texture
    /// \param path : path to texture
    Texture loadTexture(const std::string path);
    /// \brief Load a Model
    /// \param path : path to the file to load from (.obj)
    void loadModel(const char* path);

    /// \brief Process a Node from assimp
    void processNode(aiNode *node, const aiScene *scene);
    /// \brief Process a Mesh from assimp
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);

    /// \brief Draw the Model
    /// \param Shader : Shader to pass the material to
    void Draw(MyShader &Shader) const;
};