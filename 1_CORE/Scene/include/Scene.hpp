#pragma once

#include <vector>
#include <queue>
#include "SceneNode.hpp"
#include "Object.hpp"
#include "../../../2_VISU/Texture/include/Skybox.hpp"
#include "../../../2_VISU/Texture/include/InfPlane.hpp"
#include "../../../2_VISU/Shaders/include/MyShader.hpp"


#define MAX_NODE_IN_SCENE 10

class Scene {
private:
    std::vector<Road> _stock;

    std::queue<SceneNode*> _road;
    std::vector<Car*> _cars;

    InfPlane _grid;
    Skybox _moonlight;
    MyShader _shader;

    int _nbNode;

public:
    Scene();
    ~Scene() = default;

    void add();
    void init();

    void Draw(glm::mat4 ViewMat, glm::mat4 ProjMat);
    void update() const;
    void update(EFFECTS e);
};