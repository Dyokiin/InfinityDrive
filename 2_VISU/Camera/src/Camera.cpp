#include "../include/Camera.hpp"
#include <math.h>
#include <iostream>

void Camera::calcPos(){
    _camPos[0] = _transforms[0] * sin(_transforms[2]) * sin(_transforms[1]);
    _camPos[1] = _transforms[0] * cos(_transforms[1]);
    _camPos[2] = _transforms[0] * cos(_transforms[2]) * sin(_transforms[1]);
}

void Camera::moveFront(const float delta){
    _transforms[0] += delta;
}

void Camera::rotateLeft(const double a){
    double b = glm::radians(a);
    _transforms[1] += b;
}

void Camera::rotateUp(const double a){
    double b = glm::radians(a);
    _transforms[2] += b;
}

glm::mat4 const Camera::getViewMatrix() {

    this->calcPos();

    return glm::lookAt(_camPos,
                       _lookAt,
                       _upVect);
}