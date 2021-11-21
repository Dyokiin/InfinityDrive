#pragma once

#include "Object.hpp"
#include "SceneNode.hpp"

class Scene {
private:
    SceneNode* _cars;
    SceneNode* _first;
    SceneNode* _last;
    int _nbObject;

public:
    Scene();
    ~Scene();

    std::vector<ShapeVertexTex> meshify() const;
    void add(const Object* obj);
    void init();
    Object* pop();

};