#include "../include/Object.hpp"

//Draw generic object Object
void Object::Draw(MyShader &Shader) const {
    _model.Draw(Shader);
}

//Draw a RoadElements 
void Road::Draw(MyShader &Shader) const {
    this->Object::Draw(Shader);
    for(Object c : _coins)
        c.Draw(Shader);
}

//Draw complex object cars
void Car::Draw(MyShader &Shader) const {
    this->Object::Draw(Shader);
}

void Car::reset() {
    _modelMatrix *= glm::translate(glm::vec3(0,1,-_pos.z+96));
    _hitBox.translate(glm::translate(glm::vec3(0,1,-_pos.z+96)));
    _Cspeed.z = 0.2;
    _rotMatrix = glm::mat4(1.f);
}

//Update regular car behaviour and matrices
void Car::update() {
    if((_pos.y + _Cspeed.y) > 2.) {
        _Cspeed.y += _Caccel.y;
    } else {
        _Cspeed.y = 0.f;
    }

    if(_Cspeed.z < CAR_MAX_SPEED && _Cspeed.z > 0.00001) { _Cspeed.z += _Caccel.z;}

    _modelMatrix *= glm::translate(_Cspeed);
    _hitBox.translate(glm::translate(_Cspeed));

    _pos = glm::vec3(_modelMatrix * glm::vec4(1));
}

//Update Car behaviour depending on an effect (collision)
void Car::update(EFFECTS e) {
    switch (e) {
    case FALL:
        _modelMatrix *= glm::translate(glm::vec3(0,-1,0));
        _rotMatrix = glm::rotate(_rotMatrix, glm::radians(45.0f), glm::vec3(1.,0.,0.));
        _Cspeed.z = 0.;
        break;
    case SLOW:
// If Car hit SLOW effect hitbox : divide speed /  Check for low speed end trigger
        if(_Cspeed.z <= 0.1){_Cspeed.z = 0;}
        _Cspeed.z /= 1.5;
        _Caccel.z = 0.00002;
        break;
    case CAUTGH:
        _Cspeed.z = 0;
        break;
    case BURST:
        _Cspeed.z = 0;
        _rotMatrix = glm::rotate(_rotMatrix, glm::radians(90.0f), glm::vec3(1.,1.,0.));
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
// Speeds the car UP
        if(_pos.y <= 2.){_Cspeed += glm::vec3(0,0.3,0);}
        break;
    case LEFT:
// Speeds the car left
        if(_pos.x < 5 && _Cspeed.x < 0.2 && _Cspeed.z!= 0.){_Cspeed += glm::vec3(0.2,0,0); _aSpeed.z += 0.5;}
        break;
    case RIGHT:
// Speeds the car right
        if(_pos.x > -3 && _Cspeed.x > -0.2 && _Cspeed.z != 0.){_Cspeed += glm::vec3(-0.2,0,0);}
        break;
    default:  case KEEP:
//Stop the car strafe if it hits the center of a lane
        if(_pos.x >= 5){_Cspeed.x = 0;}
        else if(_pos.x <= -3) {_Cspeed.x = 0;}
        else if(_pos.x < 1.1 && _pos.x > 0.9) {_Cspeed.x = 0;}
        break;
    }
    this->update();
}

//Load all objects and sets their caracteristics
std::vector<Road> loadObject() {

    //Final Road Elements Vector
    std::vector<Road> stock;

    //Declaration and initialisation of Roads Elements

        //Straight Road        
    std::vector<Mesh> SRoad;
    SRoad.push_back(texturedPlane(glm::vec3(-6,0,48), glm::vec3(6,0,0), "../ressources/textures/SRoad.png"));
    
    stock.push_back(Road(Model(SRoad),HitBox(),Box(6,-5,0,-6,5,48),glm::translate(glm::vec3(0,0,48))));

        //With a slowing obstacle
    std::vector<Mesh> SLRoad;
    std::vector<Mesh> SRMRoad;
    std::vector<Mesh> SLRRoad;

    SLRoad.push_back(texturedPlane(glm::vec3(-6,0,48), glm::vec3(6,0,0), "../ressources/textures/Slow/SlowLRoad.png"));
    stock.push_back(Road(Model(SLRoad),HitBox(Box(3,-0.5,24,5,1.5,26), SLOW),Box(6,-5,0,-6,5,48),glm::translate(glm::vec3(0,0,48))));

    SLRRoad.push_back(texturedPlane(glm::vec3(-6,0,48), glm::vec3(6,0,0), "../ressources/textures/Slow/SlowRRoad.png"));
    stock.push_back(Road(Model(SLRRoad),HitBox(Box(-5,-0.5,24,-3,1.5,26), SLOW),Box(6,-5,0,-6,5,48),glm::translate(glm::vec3(0,0,48))));

    SRMRoad.push_back(texturedPlane(glm::vec3(-6,0,48), glm::vec3(6,0,0), "../ressources/textures/Slow/SlowRMRoad.png"));
    stock.push_back(Road(Model(SRMRoad),HitBox(Box(-5,-0.5,24,1,1.5,26), SLOW),Box(6,-5,0,-6,5,48),glm::translate(glm::vec3(0,0,48))));

        //With a fall Obstacle
    std::vector<Mesh> FLRoad;
    std::vector<Mesh> FRRoad;
    std::vector<Mesh> FMRoad;

    FLRoad.push_back(texturedPlane(glm::vec3(-6,0,48), glm::vec3(6,0,0), "../ressources/textures/Fall/FallLRoad.png"));
    stock.push_back(Road(Model(FLRoad), HitBox(Box(-1,-0.5,7,5,1.5,42), FALL), Box(6,-5,0,-6,5,48), glm::translate(glm::vec3(0,0,48))));

    FRRoad.push_back(texturedPlane(glm::vec3(-6,0,48), glm::vec3(6,0,0), "../ressources/textures/Fall/FallRRoad.png"));
    stock.push_back(Road(Model(FRRoad), HitBox(Box(-5,-0.5,7,1,1.5,42), FALL), Box(6,-5,0,-6,5,48), glm::translate(glm::vec3(0,0,48))));

    FMRoad.push_back(texturedPlane(glm::vec3(-6,0,48), glm::vec3(6,0,0), "../ressources/textures/Fall/FallMRoad.png"));
    stock.push_back(Road(Model(FMRoad), HitBox(Box(-2,-0.5,7,2,1.5,42), FALL), Box(6,-5,0,-6,5,48), glm::translate(glm::vec3(0,0,48))));

        //With a burst Obstacle : mesh perpendicular to the road
    std::vector<Mesh> BLRoad;
    std::vector<Mesh> BRRoad;
    std::vector<Mesh> BMRoad;
    std::vector<Mesh> BLMRoad;
    std::vector<Mesh> BRMRoad;

    BLRoad.push_back(texturedPlane(glm::vec3(-6,0,48), glm::vec3(6,0,0), "../ressources/textures/SRoad.png"));
    BLRoad.push_back(texturedPlane(glm::vec3(2,0,24), glm::vec3(5,2,24), "../ressources/textures/Burst/Obstacle1.1.png"));
    stock.push_back(Road(Model(BLRoad), HitBox(Box(2,0,24,5,2.5,25)), Box(6,-5,0,-6,5,48), glm::translate(glm::vec3(0,0,48))));

    BRRoad.push_back(texturedPlane(glm::vec3(-6,0,48), glm::vec3(6,0,0), "../ressources/textures/SRoad.png"));
    BRRoad.push_back(texturedPlane(glm::vec3(-5,0,24), glm::vec3(-2,2,24), "../ressources/textures/Burst/Obstacle1.1.png"));
    stock.push_back(Road(Model(BRRoad), HitBox(Box(-5,0,24,-2,2.5,25)), Box(6,-5,0,-6,5,48), glm::translate(glm::vec3(0,0,48))));

    BMRoad.push_back(texturedPlane(glm::vec3(-6,0,48), glm::vec3(6,0,0), "../ressources/textures/SRoad.png"));
    BMRoad.push_back(texturedPlane(glm::vec3(2,0,24), glm::vec3(-2,2,24), "../ressources/textures/Burst/Obstacle1.1.png"));
    stock.push_back(Road(Model(BMRoad), HitBox(Box(2,0,24,-2,2.5,25)), Box(6,-5,0,-6,5,48), glm::translate(glm::vec3(0,0,48))));

    BLMRoad.push_back(texturedPlane(glm::vec3(-6,0,48), glm::vec3(6,0,0), "../ressources/textures/SRoad.png"));
    BLMRoad.push_back(texturedPlane(glm::vec3(5.,0.,24), glm::vec3(-1.,2.,24.), "../ressources/textures/Burst/Obstacle2.png"));
    stock.push_back(Road(Model(BLMRoad), HitBox(Box(-1,0,24,5,2.5,25)), Box(6,-5,0,-6,5,48), glm::translate(glm::vec3(0,0,48))));
    
    BRMRoad.push_back(texturedPlane(glm::vec3(-6,0,48), glm::vec3(6,0,0), "../ressources/textures/SRoad.png"));
    BRMRoad.push_back(texturedPlane(glm::vec3(1,0.,24), glm::vec3(-6.,2.,24.), "../ressources/textures/Burst/Obstacle3.png"));
    stock.push_back(Road(Model(BRMRoad), HitBox(Box(-6,0,24,1,2.5,25)), Box(6,-5,0,-6,5,48), glm::translate(glm::vec3(0,0,48))));


    return stock;
}