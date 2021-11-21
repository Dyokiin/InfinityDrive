#pragma once

#include   "Object.hpp"

class SceneNode{
private:
    Object* _roadElem;
    glm::mat4 _modelMatrix;

public:
    SceneNode();
    ~SceneNode();

    inline std::vector<ShapeVertexTex> getVertex() const {return _roadElem->getVertice();};
    inline glm::mat4 getModelMatrix() const {return _modelMatrix;};

    void translate(const float tx, const float ty, const float tz);
    void rotatex(const float alpha);
    void rotatey(const float alpha);
    void rotatez(const float alpha);
};