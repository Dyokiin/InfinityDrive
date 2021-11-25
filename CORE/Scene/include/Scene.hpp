#pragma once

#include "../../../VISU/Object/include/Object.hpp"
#include "SceneNode.hpp"

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

    std::vector<ShapeVertexTex> meshify() const;
    void add(const Object* obj);
    void init();
    void pop();
};