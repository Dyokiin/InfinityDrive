#pragma once

#include "Model.hpp"
#include "../../../1_CORE/Box/include/HitBox.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>
#include <glm/gtx/norm.hpp>


#define CAR_MAX_SPEED 0.5
#define CARS_MAX_DIST 2

enum DIRECTION {JUMP, LEFT, RIGHT, KEEP};


class Object{
//protected to be used by legacy 
protected:
    Model _model;
    HitBox _hitBox;

public:
    Object();
    Object(Model model,  HitBox hitbox)
    : _model(model), _hitBox(hitbox) {}
    ~Object() = default;

    void Draw(MyShader &Shader) const;
    inline const HitBox getHitBox() const {return _hitBox;}
};

class Road : public Object {
private:
    Box _boundingBox;
    glm::mat4 _endPath;

    std::vector<Object> _coins;
    bool _realCoins;

public:
    Road() : Object() {}
    Road(Model model, HitBox hitbox, Box bndbox, glm::mat4 endpth)
    : Object(model, hitbox), _boundingBox(bndbox), _endPath(endpth) {}
    ~Road() = default;

    inline const bool isCoins() const {return _realCoins;}
    inline Box getBnBox() const {return _boundingBox;}
    inline void setCoins(bool yN) {_realCoins = yN;}
    inline glm::mat4 getEndPth() const {return _endPath;}
    void Draw(MyShader &Shader) const;
};

class Car : public Object {
private :
    glm::vec3 _pos;
    glm::vec3 _Cspeed;
    glm::vec3 _Caccel;
    glm::vec3 _aSpeed;
    glm::vec3 _aAccel;
    glm::mat4 _modelMatrix;
    glm::mat4 _rotMatrix;
    bool _targetable;

public :
    Car() : Object() {}
    Car(Model model, HitBox hitbox) 
    : Object(model, hitbox), _pos(0.f), _Cspeed(0,0,0.2), _Caccel(0.,-0.008,0.00001),
    _aSpeed(0.f), _aAccel(-0.01), _modelMatrix(1.f), _rotMatrix(1.f), _targetable(true) {
        _modelMatrix *= glm::translate(glm::vec3(0,1,96));
        _hitBox.translate(glm::translate(glm::vec3(0,1,97)));
    }

    void update();
    void update(EFFECTS e);
    void update(DIRECTION d);
    inline const glm::mat4 getModelMat() const {return _modelMatrix;}
    inline const glm::mat4 getRotModelMat() const {return _modelMatrix * _rotMatrix;}
    inline const bool isTargetable() const {return _targetable;}
    inline void toggleTarget(bool yN) {_targetable = yN;}
    void Draw(MyShader &Shader) const;
};

std::vector<Road> loadObject();