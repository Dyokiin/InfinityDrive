#pragma once

#include <vector>
#include <deque>
#include "SceneNode.hpp"
#include "Model.hpp"
#include "../../Camera/include/Camera.hpp"
#include "../../Texture/include/Skybox.hpp"
#include "../../Texture/include/InfPlane.hpp"
#include "../../Shaders/include/MyShader.hpp"


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
    ~Scene() = default;

    void add();
    void init();

    void Draw(glm::mat4 ViewMat, glm::mat4 ProjMat);
    inline const glm::mat4 getCarModelMat() const {return _cars[0]->getModelMat();}
    void update(Camera &cam) const;
    void update(EFFECTS e);
};