#pragma once

#include <SDL2/SDL.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <iostream>
#include <vector>

#include "mesh.hpp"

class Model {
private :
    std::vector<Mesh> _mesh;
    std::string _textPath;

public :
    Model(char * path) {loadModel(path);}
    Model(std::vector<Mesh> mesh)
    : _mesh(mesh) {}
    ~Model() = default;

    Texture loadTexture(const std::string path);
    void loadModel(const char* path);

    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);

    void Draw() const;
};