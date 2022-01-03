#pragma once 

#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

#define CAMERA_MAX_Y 3.1415/2 
#define CAMERA_MIN_Y 0
#define CAMERA_MAX_ZOOM 0.2
#define CAMERA_MIN_ZOOM 20

class Camera {
private:
    glm::vec3 _lookAt;  /*!< point the camera is currently looking at */
    glm::vec3 _camPos;  /*!< Position of the camera, cartesian system */
    glm::vec3 _upVect;  /*!< UP vector */

    bool _firstPerson;   /*!< is the camera in first person mod */

    glm::vec3 _transforms;  /*!< Freeball camera : spherical coordinates [0] : distance | [1] : angleX | [2] : angleY */
    glm::mat4 _modelMatrix; /*!< Model matrix of the camera */ 

public:

    /// \brief Default constructor
    Camera()
    : _lookAt(glm::vec3(0,0.5,0)), _upVect(0,1,0), _firstPerson(false), _transforms(6.f,1.f,1.f), _modelMatrix(1.f)  {
        this->calcPos();
    };
    /// \brief Constructor
    /// \param lookat : vector representing the point cam is looking at
    /// \param tranzform : vector for basic spherical coordinates
    Camera(glm::vec3 lookat, glm::vec3 tranzform)
    : _lookAt(lookat), _upVect(0,1,0), _transforms(tranzform) {
        this->calcPos();
    };

    /// \brief default constructor
    ~Camera() = default;

    /// \brief compute _camPos from _transform and _ModelMatrix
    void calcPos();

    /// \brief Move the camera along the radius axis
    /// \param delta : distance to move
    void moveFront(const float delta);
    /// \brief rotate the camera on the longitudinal axis
    /// \param alpha : angle to move
    void rotateLeft(const double alpha);
    /// \brief rotate the camera on the latitudinal axis
    /// \param gamma : angle to move
    void rotateUp(const double gamma);

    /// \brief setter for modelMatrix of the camera
    /// \param modelmat : 4x4 mtrix to set to
    inline void setModel(const glm::mat4 modelmat) {_modelMatrix = modelmat;}
    /// \brief getter for firstperson mod
    inline bool getFP() const {return _firstPerson;}

    /// \brief returns the view matrix of the camera
    glm::mat4 getViewMatrix();
};
