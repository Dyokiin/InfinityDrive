#pragma once

#include "SceneNode.hpp"
#include "../../../2_VISU/Mesh/include/mesh.hpp"

#define MAX_NODE_IN_SCENE 10

class Scene {
private:
    SceneNode* _cars;
    SceneNode* _first;
    SceneNode* _last;
    int _nbObject;

public:
    Scene();
    ~Scene();

    inline const int getNbObject() const {return _nbObject;} 

    std::vector<Vertex> meshify() const;
    void add(const Object* obj);
    void init();
    void pop();
};