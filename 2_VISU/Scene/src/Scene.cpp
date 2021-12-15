#include "../include/Scene.hpp"

void Scene::init() {

    _stock = loadObject();
    _nbNode = 0;

    glm::mat4 modelMat(1.f);
    for(int i = 0; i < MAX_NODE_IN_SCENE; i++) {
        _road.push_back(new SceneNode(&_stock[0], modelMat, i));
        modelMat *= _road.back()->getRoadTransf();
        _nbNode++;
    }

    char pathToCar[] = "../ressources/assets/car.obj";
    Car* car2000 = new Car(Model(pathToCar), HitBox(Box(-0.5,0.5,0,0.5,1.,0.5), NONE));
    //TODO : enemy model
    _cars.push_back(car2000);
}

void Scene::add() {
    //Get random Road Element form _stock

    _road.push_back(new SceneNode(&_stock[0], _road.back()->getModelMatrix() * _road.back()->getRoadTransf(), _road.back()->getPos()+1));
    _nbNode++;
    if(_nbNode > MAX_NODE_IN_SCENE) {
        _road.pop_front();
        _nbNode--;
    }
}

void Scene::Draw(glm::mat4 ViewMat, glm::mat4 ProjMat) {

    glm::mat4 VPmatrix = ProjMat * ViewMat;
    glm::mat4 PlaneMatrix = _cars[0]->getModelMat() * glm::translate(glm::vec3(0,-10,0));

    _shader.plnShader();
    _shader.sendProjModelMat(ProjMat * PlaneMatrix);
    _shader.sendMVPMat(VPmatrix * PlaneMatrix);
    _grid.render();

    _shader.triShader();
    _shader.sendMVPMat(VPmatrix * _cars[0]->getRotModelMat());
    for(auto i : _cars) i->Draw();
    for(SceneNode* i : _road) {
        _shader.sendMVPMat(VPmatrix * i->getModelMatrix());
        i->Draw();
    }

    _shader.skyShader();
    _shader.sendProjViewMat(VPmatrix);
    _moonlight.display();
}

void Scene::update(Camera &cam, const float dT, DIRECTION d) {

    for(SceneNode* i : _road) {
        // Check if the car is in this Scene Node
        if(_cars[0]->getHitBox().intersect(i->getBndBox())) {
            //TODO : if car in node check hitbox : update(effects) or not
            // Store effect, direction then car.update(EFFECT, DIRECTION) ? 
            if(i->getPos() > _road.front()->getPos() + 2) {
                this->add();
            }
        }
    }
    for(auto s : _cars)
        s->update(d);
    cam.setModel(_cars[0]->getModelMat());
}

