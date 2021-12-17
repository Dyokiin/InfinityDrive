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

    if((_pos.y + _Cspeed.y) > 1.) {
        _Cspeed.y += _Caccel.y;
    } else {
        _Cspeed.y = 0.f;
    }

    if(_Cspeed.z < CAR_MAX_SPEED) { _Cspeed.z += _Caccel.z;}

    _modelMatrix *= glm::translate(_Cspeed);
    _hitBox.translate(glm::translate(_Cspeed));

    _pos = glm::vec3(_modelMatrix * glm::vec4(1));
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
        if(_pos.y <= 1.){_Cspeed += glm::vec3(0,0.3,0);}
        break;
    case LEFT:
        if(_pos.x > 2){_Cspeed += glm::vec3(0.1,0,0);
        } else {
            _Cspeed.x = 0;
        }
        break;
    case RIGHT:

        break;
    default:  case KEEP:
        if(_pos.x < 0.1 || _pos.x > -0.1) {
            //_Cspeed += (float)(_pos.x<=0) * glm::vec3(0.1,0,0) + (float)(_pos.x>=0) * glm::vec3(-0.1,0,0);
        }
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