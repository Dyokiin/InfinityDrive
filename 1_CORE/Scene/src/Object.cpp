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


void Object::Draw(MyShader shader, const glm::mat4 MVmatrix, const glm::mat4 MVPmatrix) const {
    _model.Draw(shader, MVmatrix, MVPmatrix);
}

void Road::Draw(MyShader shader, const glm::mat4 MVmatrix, const glm::mat4 MVPmatrix) const {
    this->Object::Draw(shader, MVmatrix, MVPmatrix);
    for(auto c : _coins)
        c.Draw(shader, MVmatrix, MVPmatrix);
}

void Car::Draw(MyShader shader, const glm::mat4 MVmatrix, const glm::mat4 MVPmatrix) const {
    this->Object::Draw(shader, MVmatrix, MVPmatrix);
}