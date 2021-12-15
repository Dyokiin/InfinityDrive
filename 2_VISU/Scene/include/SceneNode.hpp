#pragma once

#include <vector>
#include <glm/glm.hpp>
#include "Object.hpp"

class SceneNode{
private:
    const Road* _roadElem;
    glm::mat4 _modelMatrix;
    Box _boundingBox;
    int _NodePosInScene;

public:
    SceneNode();
    SceneNode(const Road* obj, const glm::mat4 modelmat, const int pos)
    : _roadElem(obj), _modelMatrix(modelmat), _boundingBox(obj->getBnBox()), _NodePosInScene(pos) {_boundingBox.translate(modelmat);}
    ~SceneNode() = default;

    inline const Box getBndBox() const {return _boundingBox;} 
    inline glm::mat4 getModelMatrix() const {return _modelMatrix;}
    inline void multiMat(glm::mat4 mat) {_modelMatrix *= mat;}
    inline glm::mat4 getRoadTransf() const {return _roadElem->getEndPth();}
    inline void Draw() const {_roadElem->Draw();}
    inline int getPos() const {return _NodePosInScene;}

    void translate(const float tx, const float ty, const float tz);
    void rotatex(const float alpha);
    void rotatey(const float alpha);
    void rotatez(const float alpha);
};