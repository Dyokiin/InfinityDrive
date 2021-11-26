#include "../include/MyShader.hpp"

MyShader::MyShader(){
    
    _Shader1 = loadProgram("../ressources/shaders/vertshade.vs.glsl",
                           "../ressources/shaders/fragshade.fs.glsl");

    _Shader1.use();

}

void MyShader::sendMatrices(const glm::mat4 viewMat, const glm::mat4 projMat) const {

}