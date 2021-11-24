#include "../include/SceneNode.hpp"


SceneNode::SceneNode(){
    _roadElem = nullptr;
    _modelMatrix = glm::mat4(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
    _next = nullptr;
}

SceneNode::SceneNode(const Object* obj){
    _roadElem = obj;
    _modelMatrix = glm::mat4(1, 0, 0, 0,
                             0, 1, 0, 0,
                             0, 0, 1, 0,
                             0, 0, 0, 1);
    _next = nullptr;
}

SceneNode::~SceneNode(){
//    if(_next != nullptr){delete _next;} 
}

void SceneNode::translate(const float tx, const float ty, const float tz){
    glm::mat4 transmat = glm::mat4(1, 0, 0, 0,
                                   0, 1, 0, 0,
                                   0, 0, 1, 0,
                                   tx,ty,tz,1);
    _modelMatrix*=transmat;
}

void SceneNode::rotatex(const float a){
    glm::mat4 rotatmat = glm::mat4(1,  0,      0,      0,
                                   0,  cos(a), sin(a), 0,
                                   0, -sin(a), cos(a), 0,
                                   0,  0,      0,      1);
    _modelMatrix*=rotatmat;
}

void SceneNode::rotatey(const float a){
    glm::mat4 rotatmat = glm::mat4(cos(a), 0, -sin(a), 0,
                                   0,      1,  0,      0,
                                   sin(a), 0,  cos(a), 0,
                                   0,      0,  0,      1);
    _modelMatrix*=rotatmat;
}

void SceneNode::rotatez(const float a){
    glm::mat4 rotatmat = glm::mat4(cos(a), sin(a), 0, 0,
                                  -sin(a), cos(a), 0, 0,
                                   0,      0,      1, 0,
                                   0,      0,      0, 1);
    _modelMatrix*=rotatmat;
}