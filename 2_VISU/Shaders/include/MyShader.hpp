#pragma once

#include "../include/Program.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <SDL2/SDL.h>

class MyShader{
private:
    
    Program _Shader1;

    GLint _uniformViewMat;
    GLint _uniformProjMat;
    GLint _uniformNormMat;
    //Program _Shader2;

public:
    
    MyShader();
    ~MyShader() = default;

    void init();
    void use() const;

    inline void sendViewMat(const glm::mat4 viewMat) const {glUniformMatrix4fv(_uniformViewMat, 1, false, glm::value_ptr(viewMat));}
    inline void sendProjMat(const glm::mat4 projMat) const {glUniformMatrix4fv(_uniformProjMat, 1, false, glm::value_ptr(projMat));}
    inline void sendNormMat(const glm::mat4 normMat) const {glUniformMatrix4fv(_uniformNormMat, 1, false, glm::value_ptr(normMat));}
    inline void sendMatrixs(const glm::mat4 viewMat, const glm::mat4 projMat, const glm::mat4 normMat) const {
        sendViewMat(viewMat);
        sendProjMat(projMat);
        sendNormMat(normMat);
    }

};