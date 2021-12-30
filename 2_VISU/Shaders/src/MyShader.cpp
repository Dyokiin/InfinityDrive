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

void MyShader::sendNormalMat(const glm::mat4 ModelMat, const glm::mat4 ViewMat) const{
    glm::mat4 NormalMat = glm::transpose(glm::inverse(ViewMat*ModelMat));
    if(_inUse == 1){
        char uNormalMat[] = "uNormalMatrix";
        GLint uniformNormalMat = glGetUniformLocation(_Shader1.getGLId(), (const GLchar*)uNormalMat);
        glUniformMatrix4fv(uniformNormalMat, 1, GL_FALSE, glm::value_ptr(NormalMat));
    } else if(_inUse == 2) {
        char uNormalMat[] = "uNormalMatrix";
        GLint uniformNormalMat = glGetUniformLocation(_Shader2.getGLId(), (const GLchar*)uNormalMat);
        glUniformMatrix4fv(uniformNormalMat, 1, GL_FALSE, glm::value_ptr(NormalMat));
    }
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

void MyShader::sendMaterials(const glm::vec3 Ks, const glm::vec3 Kd) const {
    char uKs[] = "uKs";
    GLint uniformMat1 = glGetUniformLocation(_Shader2.getGLId(), (const GLchar*)uKs);
    glUniform3f(uniformMat1, Ks.x, Ks.y, Ks.z);
    char uKd[] = "uKd";
    GLint uniformMat2 = glGetUniformLocation(_Shader2.getGLId(), (const GLchar*)uKd);
    glUniform3f(uniformMat2, Kd.x, Kd.y, Kd.z);
}