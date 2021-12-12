#include "../include/Object.hpp"


void Object::Draw() const {
    _model.Draw();
}

void Road::Draw() const {
    this->Object::Draw();
    for(auto c : _coins)
        c.Draw();
}

void Car::Draw() const {
    this->Object::Draw();
}

void Car::update() {
    if(glm::length(_speed) < CAR_MAX_SPEED) {
        _speed += _accel;
    }

    _modelMatrix *= glm::translate(_speed);
}

void Car::update(EFFECTS e) {

    Car::update();
    switch (e) {
    case FALL:
        
        break;
    case SLOW:

        break;
    case CAUTGH:

        break;
    case BURST:

        break;
    case LTURN:

        break;
    case RTURN:

        break;
    case NONE: default:
        break;
    }
}

std::vector<Road> loadObject() {

    std::vector<Road> stock;
    std::vector<Mesh> meshes;

    meshes.push_back(texturedPlane(glm::vec3(-6,0.2,80), glm::vec3(6,0.2,0), "../ressources/noir.png"));
    stock.push_back(Road(Model(meshes),HitBox(),Box(-4,5,10,4,-5,0),glm::translate(glm::vec3(0,0,80))));

    return stock;
}