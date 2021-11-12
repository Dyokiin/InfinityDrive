#pragma once

#include <glm/glm.hpp>

class Box {

private:

    // Seen from front points are : 
    //_corner1 : bottom right closer to cam
    //_corner2 : top left farther

    const glm::vec3 _corner1;
    const glm::vec3 _corner2;

public:

    // Default construcor
    Box() = default; 

    // Copy constructor
    Box(const Box&);

    Box(const glm::vec3 iVec1, const glm::vec3 iVec2)
    : _corner1(iVec1), _corner2(iVec2){}


    // Full values constructor
    Box(const float x1, const float y1, const float z1, const float x2, const float y2, const float z2)
    : _corner1(x1, y1, z1), _corner2(x2, y2, z2){}


    // Default destructor
    ~Box() = default;


    // Check if a point is in a box

    bool pointInBox(const glm::vec3 &point) const;


    // Check if two Boxes intersect : Method and Operator

    bool intersect(const Box &wBox) const ;
    bool operator*(const Box &wBox) const ; 
};
