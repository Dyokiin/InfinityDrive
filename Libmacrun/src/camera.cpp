#include "Camera.hpp"
#include <glm/glm.h>

void Camera::translate(const float tx, const float ty, const float tz){
    glm::mat4 transmat = glm::mat4(1, 0, 0, 0,
                                   0, 1, 0, 0,
                                   0, 0, 1, 0,
                                   tx,ty,tz,1);
    _modelMatrix*=transmat;
}

void Camera::rotatex(const float a){
    glm::mat4 rotatmat = glm::mat4(1,  0,      0,      0,
                                   0,  cos(a), sin(a), 0,
                                   0, -sin(a), cos(a), 0,
                                   0,  0,      0,      1);
    _modelMatrix*=rotatmat;
}

void Camera::rotatey(const float a){
    glm::mat4 rotatmat = glm::mat4(cos(a), 0, -sin(a), 0,
                                   0,      1,  0,      0,
                                   sin(a), 0,  cos(a), 0,
                                   0,      0,  0,      1);
    _modelMatrix*=rotatmat;
}

void Camera::rotatez(const float a){
    glm::mat4 rotatmat = glm::mat4(cos(a), sin(a), 0, 0,
                                  -sin(a), cos(a), 0, 0,
                                   0,      0,      1, 0,
                                   0,      0,      0, 1);
    _modelMatrix*=rotatmat;
}