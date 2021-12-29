#include "../include/Scene.hpp"


// Initialize the scene : Load all road elements and fill the scene with MAX_NODE straight blocks
void Scene::init(Camera &cam) {

    _stock = loadObject();
    _nbNode = 0;

    glm::mat4 modelMat(1.f);
    //Each element have a Transform Matrix indicating how the next element must be moved to be placed right after
    for(int i = 0; i < MAX_NODE_IN_SCENE; i++) {
        _road.push_back(new SceneNode(&_stock[0], modelMat, i));
        modelMat *= _road.back()->getRoadTransf();
        _nbNode++;
    }


    char pathToCar[] = "../ressources/assets/CAR.obj";
    Car* car2000 = new Car(Model(pathToCar), HitBox(Box(-0.5,0.,0,0.5,1.,0.5), NONE));
    //TODO : enemy model
    _cars.push_back(car2000);

    cam.setModel(_cars[0]->getModelMat());
}


//add a road element a the end of the scene queue, pop first element if needed
void Scene::add() {
    //Get random Road Element form _stock

    _road.push_back(new SceneNode(&_stock[1], _road.back()->getModelMatrix() * _road.back()->getRoadTransf(), _road.back()->getPos()+1));
    _nbNode++;
    if(_nbNode > MAX_NODE_IN_SCENE) {
        _road.pop_front();
        _nbNode--;
    }
}

//Draw the whole scene : Skybox and PLane have their own shader. 
void Scene::Draw(glm::mat4 ViewMat, glm::mat4 ProjMat) {

    glm::mat4 VPmatrix = ProjMat * ViewMat;
    glm::mat4 PlaneMatrix = _cars[0]->getModelMat() * glm::translate(glm::vec3(0,-10,0));

    _shader.plnShader();
    _shader.sendProjModelMat(ProjMat * PlaneMatrix);
    _shader.sendMVPMat(VPmatrix * PlaneMatrix);
    _shader.sendNormalMat(PlaneMatrix, ViewMat);
    _grid.render();

    _shader.triShader();
//Change the Model Matrix for each element
    _shader.sendMVPMat(VPmatrix * _cars[0]->getRotModelMat());
    _shader.sendNormalMat(_cars[0]->getModelMat(), ViewMat);
    for(auto i : _cars) i->Draw();
    for(SceneNode* i : _road) {
        _shader.sendMVPMat(VPmatrix * i->getModelMatrix());
        _shader.sendNormalMat(i->getModelMatrix(), ViewMat);
        i->Draw();
    }

    _shader.skyShader();
    _shader.sendProjViewMat(VPmatrix);
    _moonlight.display();
}

//Update car Position, Check collision, Add element in scene if needed
void Scene::update(Camera &cam, const float dT, DIRECTION d) {

    EFFECTS effect = NONE; 

    for(SceneNode* i : _road) {
        // Check if the car is in this Scene Node
        if(_cars[0]->getHitBox().intersect(i->getBndBox())) {
            if(_cars[0]->getHitBox().pIntersect(i->getHitBox())){
                if(_cars[0]->isTargetable()) {
                    effect = i->getHitBox().effect();
                    _cars[0]->toggleTarget(false);
                }

            }

            //Deque iteration has undefined beahviour
            if(i->getPos() > _road.front()->getPos() + 2) {
                this->add();
                _cars[0]->toggleTarget(true);
            }
        }
    }
    _cars[0]->update(d);
    _cars[0]->update(effect);

    cam.setModel(_cars[0]->getModelMat());
}

