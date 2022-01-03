#include "../include/SceneNode.hpp"

HitBox SceneNode::getHitBox() const {
    HitBox tempHit = _roadElem->getHitBox();
    tempHit.translate(_modelMatrix);
    return tempHit;
}