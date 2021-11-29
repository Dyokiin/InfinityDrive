#pragma once 

#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
private:
    glm::vec3 _lookAt;
    glm::vec3 _camPos;
    glm::vec3 _upVect;

    glm::vec3 _transforms; //[0] : distance | [1] : angleX | [3] : angleY

public:

    Camera()
    : _lookAt(glm::vec3(0)), _upVect(0,1,0), _transforms(0.5,0,0) {
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

    inline void setLookAt(glm::vec3 const lookat) {_lookAt = lookat;}

    glm::mat4 const getViewMatrix() const;
};
