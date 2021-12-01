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

void MyShader::sendViewMat(const glm::mat4 viewMat) const {
    if(_inUse == 1){
        char uViewMat[] = "uViewMatrix";
        GLint uniformViewMat = glGetUniformLocation(_Shader1.getGLId(), (const GLchar*)uViewMat);
        glUniformMatrix4fv(uniformViewMat, 1, GL_FALSE, glm::value_ptr(viewMat));
    } else if(_inUse == 2) {
        char uViewMat[] = "uViewMatrix";
        GLint uniformViewMat = glGetUniformLocation(_Shader2.getGLId(), (const GLchar*)uViewMat);
        glUniformMatrix4fv(uniformViewMat, 1, GL_FALSE, glm::value_ptr(viewMat));
    } else {
        char uViewMat[] = "uViewMatrix";
        GLint uniformViewMat = glGetUniformLocation(_Shader3.getGLId(), (const GLchar*)uViewMat);
        glUniformMatrix4fv(uniformViewMat, 1, GL_FALSE, glm::value_ptr(viewMat));
    }
}

void MyShader::sendProjMat(const glm::mat4 projMat) const {
    if(_inUse == 1){
        char uProjMat[] = "uProjMatrix";
        GLint uniformProjMat = glGetUniformLocation(_Shader1.getGLId(), (const GLchar*)uProjMat);
        glUniformMatrix4fv(uniformProjMat, 1, GL_FALSE, glm::value_ptr(projMat));
    } else if(_inUse == 2) {
        char uProjMat[] = "uProjMatrix";
        GLint uniformProjMat = glGetUniformLocation(_Shader2.getGLId(), (const GLchar*)uProjMat);
        glUniformMatrix4fv(uniformProjMat, 1, GL_FALSE, glm::value_ptr(projMat));
    } else {
        char uProjMat[] = "uProjMatrix";
        GLint uniformProjMat = glGetUniformLocation(_Shader3.getGLId(), (const GLchar*)uProjMat);
        glUniformMatrix4fv(uniformProjMat, 1, GL_FALSE, glm::value_ptr(projMat));
    }
}

void MyShader::sendNormMat(const glm::mat4 normMat) const {
    if(_inUse == 1){
        char uNormMat[] = "uNormMatrix";
        GLint uniformNormMat = glGetUniformLocation(_Shader1.getGLId(), (const GLchar*)uNormMat);
        glUniformMatrix4fv(uniformNormMat, 1, GL_FALSE, glm::value_ptr(normMat));
    } else if(_inUse == 2) {
        char uNormMat[] = "uNormMatrix";
        GLint uniformNormMat = glGetUniformLocation(_Shader2.getGLId(), (const GLchar*)uNormMat);
        glUniformMatrix4fv(uniformNormMat, 1, GL_FALSE, glm::value_ptr(normMat));
    } else {
        char uNormMat[] = "uNormMatrix";
        GLint uniformNormMat = glGetUniformLocation(_Shader3.getGLId(), (const GLchar*)uNormMat);
        glUniformMatrix4fv(uniformNormMat, 1, GL_FALSE, glm::value_ptr(normMat));
    }
}
