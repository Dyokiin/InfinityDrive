#include "../include/Object.hpp"

// void Object::translate(glm::vec3 tvec){
//     glm::translate(_modelMatrix, tvec);
// }

// void Object::rotate(float angle, glm::vec3 axis){
//     _modelMatrix *= glm::rotate(_modelMatrix, angle, axis.x, axis.y, axis.z);
// }

// void Object::scale(glm::vec3 svec){
//     glm::scale(_modelMatrix, svec);
// }


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
        /* code */
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