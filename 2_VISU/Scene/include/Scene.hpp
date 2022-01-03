#pragma once

#include <vector>
#include <deque>
#include <random>
#include <chrono>
#include "SceneNode.hpp"
#include "Model.hpp"
#include "../../Camera/include/Camera.hpp"
#include "../../Texture/include/Skybox.hpp"
#include "../../Texture/include/InfPlane.hpp"
#include "../../Shaders/include/MyShader.hpp"

// Far plane : more would be useless
#define MAX_NODE_IN_SCENE 10

/// \class Scene
/// \brief Scene class : core of the game
class Scene {
private:
    std::vector<Road> _stock;       /*!< All of the loaded Road Elements are stocked there */

    std::deque<SceneNode*> _road;   /*!< The displayable Road */
    std::vector<Car*> _cars;        /*!< The displayale Cars */

    InfPlane _grid;                 /*!< Ground below the Road */
    Skybox _moonlight;              /*!< Skybox */
    MyShader _shader;               /*!< All the Shaders */

    int _nbNode;                    /*!< Nombre de Node présents dans la scène */

public:
    /// \brief Constructor
    Scene() = default;

    //TODO : True destructor -> small memory leak form deque and cars on program end 
    /// \brief Destructor
    ~Scene() = default;

    /// \brief add an element to the scene
    void add();
    /// \brief Init the scene
    /// \param cam : To set its Model Matrix
    void init(Camera &cam);

    /// \brief Draws the scene
    /// \param ViewMat : View Matrix from the camera
    /// \param ProjMat : Projection Matrix
    /// \param fp : is camera in first person state
    void Draw(glm::mat4 ViewMat, glm::mat4 ProjMat, const bool fp);
    /// \brief Getter for Car Model Matrix
    inline const glm::mat4 getCarModelMat() const {return _cars[0]->getModelMat();}
//dT for even updates, even with high / low framerate
    /// \brief Updates all elements and step
    /// \param cam : camera to update its Model Matrix
    /// \param dT : d Time
    /// \param d : Direction to update cars
    void update(Camera &cam, const float dT, DIRECTION d);
};