#include "../include/Box.hpp"



bool Box::pointInBox(const glm::vec3 &point) const{
    return (_corner2.x <= point.x && point.x <= _corner1.x
         && _corner2.y <= point.y && point.y <= _corner2.z
         && _corner2.z <= point.z && point.z <= _corner1.z);
}

bool Box::intersect(const Box &wBox) const {
    return (   wBox.pointInBox(glm::vec3(_corner2.x + _corner1.x, _corner2.y, _corner2.z))
            || wBox.pointInBox(glm::vec3(_corner2.x, _corner2.y + _corner1.y, _corner2.z))
            || wBox.pointInBox(glm::vec3(_corner2.x + _corner1.x, _corner2.y + _corner1.y , _corner2.z))
            || wBox.pointInBox(_corner2)
            || wBox.pointInBox(glm::vec3(_corner1.x + _corner2.x, _corner1.y, _corner1.z))
            || wBox.pointInBox(glm::vec3(_corner1.x, _corner1.y + _corner2.y, _corner1.z))
            || wBox.pointInBox(glm::vec3(_corner1.x + _corner2.x, _corner1.y + _corner2.y , _corner1.z))
            || wBox.pointInBox(_corner1));

}

bool Box::operator*(const Box &wBox) const {
    return this->intersect(wBox);
}

Box& Box::operator=(const Box &xBox) {
    if(this == &xBox)
        return *this;
    
    _corner1 = xBox._corner1;
    _corner2 = xBox._corner2;

    return *this;
}