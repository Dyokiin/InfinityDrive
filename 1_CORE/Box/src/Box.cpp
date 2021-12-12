#include "../include/Box.hpp"



bool Box::pointInBox(const glm::vec3 &point) const{
    return (_corner2.x <= point.x && point.x <= _corner1.x
         && _corner2.y <= point.y && point.y <= _corner2.z
         && _corner2.z <= point.z && point.z <= _corner1.z);
}

bool Box::intersect(const Box &wBox) const {
    return (wBox.pointInBox(_corner2) || wBox.pointInBox(_corner1));

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

std::string Box::toString() const {
    std::string returnString = "Box : corner 1 = ";
    returnString += (int)_corner1.x;
    returnString += " ";
    returnString += (int)_corner1.y;
    returnString += " ";
    returnString += (int)_corner1.z;
    returnString += " ";
    returnString += " corner 2 = ";
    returnString += (int)_corner2.x;
    returnString += " ";
    returnString += (int)_corner2.y;
    returnString += " ";
    returnString += (int)_corner2.z;
    returnString += " ";

    std::cout << returnString << std::endl;

    return returnString;
}