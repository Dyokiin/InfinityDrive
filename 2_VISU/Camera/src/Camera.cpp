#include "../include/Camera.hpp"
#include <math.h>
#include <iostream>

void Camera::calcPos(){
    _camPos.x = (double)_transforms.x * sinf(_transforms.z) * sinf(_transforms.y);
    _camPos.y = (double)_transforms.x * cosf(_transforms.y);
    _camPos.z = (double)_transforms.x * cosf(_transforms.z) * sinf(_transforms.y);
}

void Camera::moveFront(const float delta){
    _transforms.x += delta;
    this->calcPos();
}

void Camera::rotateLeft(const double a){
    double b = glm::radians(a);
    _transforms.y += b;
    this->calcPos();
}

void Camera::rotateUp(const double a){
    double b = glm::radians(a);
    _transforms.z += b;
    this->calcPos();
}

glm::mat4 Camera::getViewMatrix() {

    return glm::lookAt(_camPos,
                       _lookAt,
                       _upVect);
}