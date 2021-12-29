#include "../include/Box.hpp"



bool Box::pointInBox(const glm::vec3 &point) const{
    return (point.x <= _corner1.x && point.x >= _corner2.x) &&
           (point.y >= _corner1.y && point.y <= _corner2.y) &&
           (point.z >= _corner1.z && point.z <= _corner2.z);
}

bool Box::pPointInBox(const glm::vec3 &point)const{
    return (point.x >= _corner1.x && point.x <= _corner2.x) &&
           (point.y >= _corner1.y && point.y <= _corner2.y) &&
           (point.z >= _corner1.z && point.z <= _corner2.z);   
}



bool Box::intersect(const Box &wBox) const {
    return (wBox.pointInBox(_corner2) || wBox.pointInBox(_corner1));

}

bool Box::pIntersect(const Box &wBox) const {
    return (wBox.pPointInBox(_corner2) || wBox.pPointInBox(_corner1));
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

void Box::translate(glm::mat4 transMat) {
    _corner1 = glm::vec3(transMat * glm::vec4(_corner1, 1));
    _corner2 = glm::vec3(transMat * glm::vec4(_corner2, 1));
}

void Box::printB() const {
    std::cout << "corner 1 : x = " << _corner1.x << " y = " << _corner1.y << " z = " << _corner1.z;
    std::cout << "  |  corner 2 : x = " << _corner2.x << " y = " << _corner2.y << " z = " << _corner2.z;
    std::cout << std::endl;
}