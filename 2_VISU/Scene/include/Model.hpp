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
    glm::vec3 _Kd;
    glm::vec3 _Ks;

public :
    Model(char * path) {loadModel(path);}
    Model(std::vector<Mesh> mesh)
    : _mesh(mesh), _Kd(0.01), _Ks(0.01) {}
    Model(char * path, glm::vec3 Ks, glm::vec3 Kd)
    : _Kd(Kd), _Ks(Ks) {loadModel(path);}
    ~Model() = default;

    Texture loadTexture(const std::string path);
    void loadModel(const char* path);

    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);

    void Draw(MyShader &Shader) const;
};