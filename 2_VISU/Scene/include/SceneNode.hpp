#pragma once

#include <vector>
#include <glm/glm.hpp>
#include "Object.hpp"

/// \class SceneNode
/// \brief Main element of the Scene : == Road
class SceneNode{
private:
    const Road* _roadElem;  /*!< Pointor to a Road present in stock */
    glm::mat4 _modelMatrix; /*!< Model Matrix of the Node */
    Box _boundingBox;       /*!< Bounding Box of the Road in the Node */

    int _NodePosInScene;    /*!< Position of the Node in the scene : Iterator has undefinied behaviour */

public:
    /// \brief Constructor
    SceneNode();
    /// \brief Constructor
    /// \param obj : ptr to a Road element
    /// \param modelmat : Model Matrix
    /// \param pos : Position of Node in the scene
    SceneNode(const Road* obj, const glm::mat4 modelmat, const int pos)
    : _roadElem(obj), _modelMatrix(modelmat), _boundingBox(obj->getBnBox()), _NodePosInScene(pos) {_boundingBox.translate(modelmat);}
    /// \brief Destructor
    ~SceneNode() = default;

//Some getters / setters
    /// \brief Getter for boundingBox
    inline const Box getBndBox() const {return _boundingBox;} 
    /// \brief Getter for ModelMatrix
    inline glm::mat4 getModelMatrix() const {return _modelMatrix;}
    /// \brief Allows mulltiplication of the Node's Model Matrix
    /// \param mat : mat to multiply Model with
    inline void multiMat(glm::mat4 mat) {_modelMatrix *= mat;}
    /// \brief Getter for End Path
    inline glm::mat4 getRoadTransf() const {return _roadElem->getEndPth();}
    /// \brief Draw the Node
    /// \param Shader : material
    inline void Draw(MyShader &Shader) const {_roadElem->Draw(Shader);}
    /// \brief Getter for Node's position
    inline int getPos() const {return _NodePosInScene;}
    /// \brief Getter for Hitbox
    HitBox getHitBox() const;
};