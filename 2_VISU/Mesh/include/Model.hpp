#pragma once

#include "mesh.hpp"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <iostream>

class Model {
private :
    std::vector<Mesh> _mesh;
    std::string _path;

public :
    Model(char * path) {loadModel(path);}
    ~Model() = default;

    Texture loadTexture(const std::string path);
    void loadModel(const std::string path);

    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);

    void Draw(const MyShader shader) const;
};