#pragma once

#include <vector>
#include <glm/glm.hpp>
#include "Object.hpp"

class SceneNode{
private:
    const Object* _roadElem;
    glm::mat4 _modelMatrix;
    Box _boundingBox;

public:
    SceneNode();
    SceneNode(const Object* obj);
    ~SceneNode() = default;

    inline glm::mat4 getModelMatrix() const {return _modelMatrix;}
    inline void multiMat(glm::mat4 mat) {_modelMatrix *= mat;}

    void translate(const float tx, const float ty, const float tz);
    void rotatex(const float alpha);
    void rotatey(const float alpha);
    void rotatez(const float alpha);
};