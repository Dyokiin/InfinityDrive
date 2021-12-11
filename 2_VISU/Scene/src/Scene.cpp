#include "../include/Scene.hpp"

void Scene::init() {

    _stock = loadObject();
    _nbNode = 0;

    glm::mat4 modelMat(1.f);
    for(int i = 0; i < MAX_NODE_IN_SCENE; i++) {
        _road.push(new SceneNode(&_stock[0], modelMat));
        modelMat *= _road.back()->getRoadTransf();
        _nbNode++;
    }

    char pathToCar[] = "../ressources/assets/car.obj";
    Car* car2000 = new Car(Model(pathToCar), HitBox());
    //TODO : enemy model
    _cars.push_back(car2000);
}

void Scene::add() {
    //Get random Road Element form _stock
    _road.push(new SceneNode(&_stock[0], _road.back()->getRoadTransf()));
    _nbNode++;
    if(_nbNode > MAX_NODE_IN_SCENE) {
        _road.pop();
    }
}

void Scene::Draw(glm::mat4 ViewMat, glm::mat4 ProjMat) {

    _shader.plnShader();
    _shader.sendProjMat(ProjMat);
    _shader.sendViewMat(ViewMat);
    _shader.sendNormMat(_cars[0]->getModelMat());
    _grid.render();

    //TODO : Render SceneNodes with apropriate Shader

    _shader.triShader();
	_shader.sendViewMat(ViewMat);
	_shader.sendProjMat(ProjMat);
    _shader.sendNormMat(_cars[0]->getModelMat());
    _cars[0]->Draw();

    _shader.skyShader();
    _shader.sendProjMat(ProjMat);
    _shader.sendViewMat(ViewMat);
    _moonlight.display();

}

void Scene::update(Camera &cam) const {
    for(auto s : _cars)
        s->update();
    
    cam.setModel(_cars[0]->getModelMat());
    //_grid.setModel(_cars[0]->getModelMat()); //TODO
}

void Scene::update(EFFECTS e) {
    for(auto s : _cars)
        s->update(e);
}