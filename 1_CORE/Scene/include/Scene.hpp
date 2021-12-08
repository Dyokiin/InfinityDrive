#pragma once

#include <vector>
#include <queue>
#include "SceneNode.hpp"
#include "../../../2_VISU/Mesh/include/mesh.hpp"

#define MAX_NODE_IN_SCENE 10

class Scene {
private:
    std::queue<SceneNode*> _road;
    std::vector<Car*> _cars;

public:
    Scene();
    ~Scene() = default;

    std::vector<Vertex> meshify() const;
    void add(const Object* obj);
    void init();
};