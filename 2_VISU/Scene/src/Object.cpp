#include "../include/Object.hpp"

//self explanatory
void Object::Draw() const {
    _model.Draw();
}

//self explanatory
void Road::Draw() const {
    this->Object::Draw();
    for(Object c : _coins)
        c.Draw();
}

//self explanatory
void Car::Draw() const {
    this->Object::Draw();
}

//Update regular car behaviour and matrices
void Car::update() {
    if((_pos.y + _Cspeed.y) > 2.) {
        _Cspeed.y += _Caccel.y;
    } else {
        _Cspeed.y = 0.f;
    }

    if(_Cspeed.z < CAR_MAX_SPEED && _Cspeed.z > 0.00001) { _Cspeed.z += _Caccel.z;}

    _rotMatrix = glm::rotate(_rotMatrix, glm::length(_aSpeed), _aSpeed);

    _modelMatrix *= glm::translate(_Cspeed);
    _hitBox.translate(glm::translate(_Cspeed));

    _pos = glm::vec3(_modelMatrix * glm::vec4(1));
}

//Update Car behaviour depending on an effect (collision)
void Car::update(EFFECTS e) {
    switch (e) {
    case FALL:
        
        break;
    case SLOW:
        if(_Cspeed.z <= 0.1){_Cspeed.z = 0;}
        _Cspeed.z /= 1.5;
        _Caccel.z = 0.00002;
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

//Update Car behaviour from a DIRECTION
void Car::update(DIRECTION d){
    switch (d)
    {
    case JUMP:
        if(_pos.y <= 2.){_Cspeed += glm::vec3(0,0.3,0);}
        break;
    case LEFT:
        if(_pos.x < 5 && _Cspeed.x < 0.2){_Cspeed += glm::vec3(0.2,0,0); _aSpeed.z += 0.5;}
        break;
    case RIGHT:
    if(_pos.x > -3 && _Cspeed.x > -0.2){_Cspeed += glm::vec3(-0.2,0,0);}
        break;
    default:  case KEEP:
    //Stop the car if it hits the center of a lane
        if(_pos.x >= 5){_Cspeed.x = 0;}
        else if(_pos.x <= -3) {_Cspeed.x = 0;}
        else if(_pos.x < 1.1 && _pos.x > 0.9) {_Cspeed.x = 0;}
        break;
    }
    this->update();
}

//Load all objects and sets their caracteristics
std::vector<Road> loadObject() {

    std::vector<Road> stock;

    std::vector<Mesh> SRoad;
    std::vector<Mesh> SLRoad;
    std::vector<Mesh> SRMRoad;
    std::vector<Mesh> SLRRoad;

    SRoad.push_back(texturedPlane(glm::vec3(-6,0,48), glm::vec3(6,0,0), "../ressources/textures/SRoad.png"));
    stock.push_back(Road(Model(SRoad),HitBox(),Box(6,-5,0,-6,5,48),glm::translate(glm::vec3(0,0,48))));

    SLRoad.push_back(texturedPlane(glm::vec3(-6,0,48), glm::vec3(6,0,0), "../ressources/textures/SlowLRoad.png"));
    stock.push_back(Road(Model(SLRoad),HitBox(Box(3,-0.5,24,5,1.5,26), SLOW),Box(6,-5,0,-6,5,48),glm::translate(glm::vec3(0,0,48))));

    SLRRoad.push_back(texturedPlane(glm::vec3(-6,0,48), glm::vec3(6,0,0), "../ressources/textures/SlowRRoad.png"));
    stock.push_back(Road(Model(SLRRoad),HitBox(Box(6,-0.5,24,-6,1.5,26), SLOW),Box(6,-5,0,-6,5,48),glm::translate(glm::vec3(0,0,48))));

    SRMRoad.push_back(texturedPlane(glm::vec3(-6,0,48), glm::vec3(6,0,0), "../ressources/textures/SlowRMRoad.png"));
    stock.push_back(Road(Model(SRMRoad),HitBox(Box(-5,-0.5,24,-3,1.5,26), SLOW),Box(6,-5,0,-6,5,48),glm::translate(glm::vec3(0,0,48))));
    
    // meshes.push_back(texturedPlane(glm::vec3(-6,0,48), glm::vec3(6,0,0), "../ressources/textures/SlowLRRoad.png"));

    return stock;
}