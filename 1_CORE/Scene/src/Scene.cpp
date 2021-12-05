#include "../include/Scene.hpp"

Scene::Scene(){
    _cars = nullptr;
    _first = nullptr;
    _last = nullptr;
    _nbObject = 0;
}

Scene::~Scene(){
    if(_cars != nullptr){delete _cars;}
}

void Scene::add(const Object* obj){
    assert(_cars != nullptr && _first != nullptr && "Scene is empty or not fully initialized");
    
    SceneNode* newSNode =  new SceneNode(obj);

    //newSNode->multiMat(_last->getModelMatrix()*_last->getFNO());

    _last->next(newSNode);
    _last = newSNode;

    _nbObject++;
    if(_nbObject >= MAX_NODE_IN_SCENE){
        this->pop();
    }
}

void Scene::pop(){
    assert(_cars != nullptr && _first != nullptr && "Scene is empty or not fully initialized");

    _cars->next()->next(_first->next());
    delete _first;
    _first = _cars->next()->next();
    
    _nbObject--;
}

void Scene::init(){
    //TODO
}

std::vector<Vertex> Scene::meshify() const {
    //TODO
}