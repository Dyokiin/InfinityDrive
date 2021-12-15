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
    if((_Cspeed.y + _Caccel.y) < 0){
        _Cspeed.y = 0;
    } else {_Cspeed.y += _Caccel.y; std::cout << _Cspeed.y << std::endl;} 
    if(glm::length(_Cspeed) < CAR_MAX_SPEED) {
        _Cspeed.x += _Caccel.x;
        _Cspeed.z += _Caccel.z;
    }
    if(!(((_aSpeed.x + _aAccel.x) < 0) && ((_aSpeed.y + _aAccel.y) < 0)) && ((_aSpeed.z + _aAccel.z) < 0)){
        _aSpeed += _aAccel;
        _rotMatrix = glm::rotate(glm::l1Norm(_aSpeed), glm::normalize(_aSpeed));
    } else {
        _aSpeed = glm::vec3(0);
        _rotMatrix = glm::mat4(1.f);
    }
    _modelMatrix *= glm::translate(_Cspeed);

    _hitBox.translate(glm::translate(_Cspeed));
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

void Car::update(DIRECTION d){
    switch (d)
    {
    case JUMP:
        _Cspeed += glm::vec3(0,0.5,0);
        break;
    case LEFT:

        break;
    case RIGHT:

        break;
    default: KEEP:
        break;
    }
    this->update();
}

std::vector<Road> loadObject() {

    std::vector<Road> stock;
    std::vector<Mesh> meshes;

    meshes.push_back(texturedPlane(glm::vec3(-6,0,48), glm::vec3(6,0,0), "../ressources/SRoad.png"));
    stock.push_back(Road(Model(meshes),HitBox(),Box(6,-5,0,-6,5,48),glm::translate(glm::vec3(0,0,48))));

    return stock;
}