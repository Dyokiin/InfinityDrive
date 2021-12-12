#include "../include/Scene.hpp"

void Scene::init() {

    _stock = loadObject();
    _nbNode = 0;

    glm::mat4 modelMat(1.f);
    for(int i = 0; i < MAX_NODE_IN_SCENE; i++) {
        _road.push_back(new SceneNode(&_stock[0], modelMat));
        modelMat *= _road.back()->getRoadTransf();
        _nbNode++;
    }

    char pathToCar[] = "../ressources/assets/car.obj";
    Car* car2000 = new Car(Model(pathToCar), HitBox(Box(-0.5,0,0,0.5,0.5,0.5), NONE));
    //TODO : enemy model
    _cars.push_back(car2000);
}

void Scene::add() {
    //Get random Road Element form _stock
    _road.push_back(new SceneNode(&_stock[0], _road.back()->getRoadTransf()));
    _nbNode++;
    if(_nbNode > MAX_NODE_IN_SCENE) {
        _road.pop_front();
    }
}

void Scene::Draw(glm::mat4 ViewMat, glm::mat4 ProjMat) {

    glm::mat4 VPmatrix = ProjMat * ViewMat;

    _shader.plnShader();
    _shader.sendProjModelMat(ProjMat * _cars[0]->getModelMat());
    _shader.sendMVPMat(VPmatrix * _cars[0]->getModelMat());
    _grid.render();

    _shader.triShader();
    _shader.sendMVPMat(VPmatrix * _cars[0]->getModelMat());
    for(auto i : _cars) i->Draw();
    for(SceneNode* i : _road) {
        _shader.sendMVPMat(VPmatrix * i->getModelMatrix());
        i->Draw();
    }

    _shader.skyShader();
    _shader.sendProjViewMat(VPmatrix);
    _moonlight.display();
}

void Scene::update(Camera &cam) {
    int iter = 0;

    for(SceneNode* i : _road) {
        // Check if the car is in this Scene Node
        std::cout << _cars[0]->getHitBox().toString() << std::endl;
        std::cout << i->getBndBox().toString() << std::endl;
        if(_cars[0]->getHitBox().intersect(i->getBndBox())) {
            std::cout << "oui" << std::endl;
            //TODO : if car in node check hitbox : update(effects) or not
            if(iter > 2) {this->add();}
        }
        iter++;
    }

    for(auto s : _cars)
        s->update();
    cam.setModel(_cars[0]->getModelMat());
}

