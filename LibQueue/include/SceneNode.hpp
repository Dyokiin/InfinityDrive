#pragma once

#include "Object.hpp"
#include "../../FileBrowse/include/FileBrowse.hpp"

class SceneNode{
private:
    const Object* _roadElem;
    glm::mat4 _modelMatrix;
    SceneNode* _next;

public:
    SceneNode();
    SceneNode(const Object* obj);
    ~SceneNode();

    inline std::vector<ShapeVertexTex> getVertex() const {return _roadElem->getVertice();}
    inline glm::mat4 getModelMatrix() const {return _modelMatrix;}
    inline SceneNode* next() const {return _next;}
    inline void next(SceneNode* newNext) {_next = newNext;}
    inline glm::mat4 getFNO() const {return _roadElem->getMatFNO();}

    inline void multiMat(glm::mat4 mat) {_modelMatrix *= mat;}

    void translate(const float tx, const float ty, const float tz);
    void rotatex(const float alpha);
    void rotatey(const float alpha);
    void rotatez(const float alpha);
};