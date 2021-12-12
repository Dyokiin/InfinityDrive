#include "../include/MyShader.hpp"

MyShader::MyShader(){

    std::string path = SDL_GetBasePath();
    
    _Shader1 = loadProgram(path + "../ressources/shaders/vertshade.vs.glsl",
                           path + "../ressources/shaders/fragshade.fs.glsl");
    _Shader2 = loadProgram(path + "../ressources/shaders/triangle.vs.glsl",
                           path + "../ressources/shaders/triangle.fs.glsl");
    _Shader3 = loadProgram(path + "../ressources/shaders/skybox.vs.glsl",
                           path + "../ressources/shaders/skybox.fs.glsl");
}

void MyShader::sendProjViewMat(const glm::mat4 projviewMat) const {
    char uPVMat[] = "uProjViewMatrix";
    GLint uniformPVMat = glGetUniformLocation(_Shader3.getGLId(), (const GLchar*)uPVMat);
    glUniformMatrix4fv(uniformPVMat, 1, GL_FALSE, glm::value_ptr(projviewMat));
}

void MyShader::sendProjModelMat(const glm::mat4 projmodelMat) const {
    char uPMMat[] = "uProjModelMatrix";
    GLint uniformPMMat = glGetUniformLocation(_Shader1.getGLId(), (const GLchar*)uPMMat);
    glUniformMatrix4fv(uniformPMMat, 1, GL_FALSE, glm::value_ptr(projmodelMat));
}

void MyShader::sendMVPMat(const glm::mat4 MVPMat) const {
    if(_inUse == 1){
        char uMVPMat[] = "uMVPMatrix";
        GLint uniformMVPMat = glGetUniformLocation(_Shader1.getGLId(), (const GLchar*)uMVPMat);
        glUniformMatrix4fv(uniformMVPMat, 1, GL_FALSE, glm::value_ptr(MVPMat));
    } else if(_inUse == 2) {
        char uMVPMat[] = "uMVPMatrix";
        GLint uniformMVPMat = glGetUniformLocation(_Shader2.getGLId(), (const GLchar*)uMVPMat);
        glUniformMatrix4fv(uniformMVPMat, 1, GL_FALSE, glm::value_ptr(MVPMat));
    }
}