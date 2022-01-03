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
    // Car Materials
    glm::vec3 Kd = glm::vec3(0.1,0.1,0.9);
    glm::vec3 Ks = glm::vec3(0,0,0.7);

    Car* car2000 = new Car(Model(pathToCar, Ks, Kd), HitBox(Box(-0.5,0.,0,0.5,1.,0.5), NONE));
    //TODO : enemy model
    _cars.push_back(car2000);

    cam.setModel(_cars[0]->getModelMat());
}


//add a road element a the end of the scene queue, pop first element if needed
void Scene::add() {
    //Get random Road Element form _stock
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();    
    std::mt19937 generator(seed);
    std::uniform_int_distribution<int> uniformIntDistribution(0,_stock.size()-1);
    int next = uniformIntDistribution(generator);

    _road.push_back(new SceneNode(&_stock[next], _road.back()->getModelMatrix() * _road.back()->getRoadTransf(), _road.back()->getPos()+1));
    _nbNode++;
    if(_nbNode > MAX_NODE_IN_SCENE) {
        _road.pop_front();
        _nbNode--;
    }
}

//Draw the whole scene : Skybox and PLane have their own shader. 
void Scene::Draw(glm::mat4 ViewMat, glm::mat4 ProjMat, const bool fp) {

    glm::mat4 VPmatrix = ProjMat * ViewMat;
    glm::mat4 PlaneMatrix = _cars[0]->getModelMat() * glm::translate(glm::vec3(0,-10,0));

    //Draw The Proceduraly Textured Plane
    _shader.plnShader();
    _shader.sendProjModelMat(ProjMat * PlaneMatrix);
    _shader.sendMVPMat(VPmatrix * PlaneMatrix);
    _shader.sendNormalMat(PlaneMatrix, ViewMat);
    _grid.render();

    //Draw the Skybox
    _shader.skyShader();
    _shader.sendProjViewMat(VPmatrix);
    _moonlight.display();

    //Draw Cars and Road
    _shader.triShader();
    //Change the Model Matrix for each element
    _shader.sendMVPMat(VPmatrix * _cars[0]->getRotModelMat());
    _shader.sendNormalMat(_cars[0]->getModelMat(), ViewMat);

    if(!fp){for(auto i : _cars) i->Draw(_shader);}
    for(SceneNode* i : _road) {
        _shader.sendMVPMat(VPmatrix * i->getModelMatrix());
        _shader.sendNormalMat(i->getModelMatrix(), ViewMat);
        i->Draw(_shader);
    }


}

//Update car Position, Check collision, Add element in scene if needed
void Scene::update(Camera &cam, const float dT, DIRECTION d) {

    EFFECTS effect = NONE; 

    for(SceneNode* i : _road) {

        // Check if the car is in this Scene Node
        if(_cars[0]->getHitBox().intersect(i->getBndBox())) {

            // Check if it hits anything in this sceneNode
            if(_cars[0]->getHitBox().pIntersect(i->getHitBox())){

                // If yes, affect the car, make it untargatable till next SceneNode
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