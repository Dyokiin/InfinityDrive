#pragma once

#include <glm/glm.hpp>
#include <string>
#include <iostream>


/// \class Box
/// \brief class allowing me to define and use axis aligned boxes
class Box {

private:

    // Seen from front points are : 
    //_corner1 : bottom right closer to cam
    //_corner2 : top left farther

    glm::vec3 _corner1;   /*!< Bottom right corner of the box */
    glm::vec3 _corner2;   /*!< top left corner of the box */

public:

    /// \brief construcor
    Box() = default; 

    /// \brief Constructor from two vectors that represent both corners of the box
    /// \param iVec1 : Bottom right corner, closer to camera
    /// \param iVec2 : Top Left corner, farther from camera
    Box(const glm::vec3 iVec1, const glm::vec3 iVec2)
    : _corner1(iVec1), _corner2(iVec2){}


    /// \brief Full value constructor to avoid defining two vectors
    Box(const float x1, const float y1, const float z1, const float x2, const float y2, const float z2)
    : _corner1(x1, y1, z1), _corner2(x2, y2, z2){}


    /// \brief destructor
    ~Box() = default;

    /// \brief Fonction used to translate a box
    /// \param transMat : 4x4 Translation Matrix
    void translate(glm::mat4 transMat);

    /// \brief Fonction used to check if a point is in the box
    /// \param point : point to check
    bool pointInBox(const glm::vec3 &point) const;
    /// \brief Fonction used to check if a point is in the box
    /// \param point : point to check
    bool pPointInBox(const glm::vec3 &point) const;

    /// \brief Cout the box : debbuging end
    void printB() const ;

    // Check if two Boxes intersect : Method and Operator

    /// \brief Check if two boxes intersects
    /// \param wBox : the other box to check
    bool intersect(const Box &wBox) const ;
    /// \brief Check if two boxes intersects
    /// \param wBox : the other box to check
    bool pIntersect(const Box &wBox) const;
    /// \brief Check if two boxes intersects
    /// \param wBox : the other box to check
    bool operator*(const Box &wBox) const ;
    /// \brief Equals operator
    /// \param wBox : Box to compare to
    Box& operator=(const Box &wBox);
};
