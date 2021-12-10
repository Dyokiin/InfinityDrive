#include "../include/Camera.hpp"
#include <math.h>
#include <iostream>

void Camera::calcPos(){
    _camPos.x = (double)_transforms.x * sinf(_transforms.z) * sinf(_transforms.y);
    _camPos.y = (double)_transforms.x * cosf(_transforms.y);
    _camPos.z = (double)_transforms.x * cosf(_transforms.z) * sinf(_transforms.y);
}

void Camera::moveFront(const float delta){
    if((_transforms.x - delta) > CAMERA_MAX_ZOOM && (_transforms.x - delta) < CAMERA_MIN_ZOOM)
        {_transforms.x -= delta;}
    this->calcPos();
}

void Camera::rotateLeft(const double a){
    double b = glm::radians(a);
    if((_transforms.y + a) > CAMERA_MIN_Y && (_transforms.y + a) < CAMERA_MAX_Y)
         {_transforms.y += b;}
    this->calcPos();
}

void Camera::rotateUp(const double a){
    double b = glm::radians(a);
    _transforms.z += b;
    this->calcPos();
}

glm::mat4 Camera::getViewMatrix() {

    glm::vec4 modelVec = _modelMatrix * glm::vec4(_camPos, 1) ;
    glm::vec4 modelLookAt = _modelMatrix * glm::vec4(_lookAt, 1) ;

    return glm::lookAt(glm::vec3(modelVec),
                       glm::vec3(modelLookAt),
                       _upVect);
}