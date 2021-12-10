#pragma once 

#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

#define CAMERA_MAX_Y 3.1415/2
#define CAMERA_MIN_Y 0
#define CAMERA_MAX_ZOOM 0.2
#define CAMERA_MIN_ZOOM 10

class Camera {
private:
    glm::vec3 _lookAt;
    glm::vec3 _camPos;
    glm::vec3 _upVect;

    bool _firstPerson;

    glm::vec3 _transforms; //[0] : distance | [1] : angleX | [2] : angleY
    glm::mat4 _modelMatrix;

public:

    Camera()
    : _lookAt(glm::vec3(0,0.5,0)), _upVect(0,1,0),_firstPerson(false), _transforms(3.f,1.f,1.f), _modelMatrix(1.f)  {
        this->calcPos();
    };
    Camera(glm::vec3 lookat, glm::vec3 tranzform)
    : _lookAt(lookat), _upVect(0,1,0), _transforms(tranzform) {
        this->calcPos();
    };
    ~Camera() = default;

    void calcPos();

    void moveFront(const float delta);
    void rotateLeft(const double alpha);
    void rotateUp(const double gamma);

    inline void setModel(const glm::mat4 modelmat) {_modelMatrix = modelmat;}

    glm::mat4 getViewMatrix();
};
