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

class Scene {
private:
    std::vector<Road> _stock;

    std::deque<SceneNode*> _road;
    std::vector<Car*> _cars;

    InfPlane _grid;
    Skybox _moonlight;
    MyShader _shader;

    int _nbNode;

public:
    Scene() = default;

    //TODO : True destructor -> small memory leak form deque and cars on program end 
    ~Scene() = default;

    void add();
    void init(Camera &cam);

    void Draw(glm::mat4 ViewMat, glm::mat4 ProjMat, const bool fp);
    inline const glm::mat4 getCarModelMat() const {return _cars[0]->getModelMat();}
//dT for even updates, even with high / low framerate
    void update(Camera &cam, const float dT, DIRECTION d);
};