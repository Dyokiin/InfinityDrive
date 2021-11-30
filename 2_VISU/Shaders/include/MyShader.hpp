#pragma once

#include "../include/Program.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <SDL2/SDL.h>

class MyShader{
private:
    
    Program _Shader1;
    Program _Shader2;
    Program _Shader3;

    int _inUse;

public:
    
    MyShader();
    ~MyShader() = default;

    void init();
    void use() const;

    void sendViewMat(const glm::mat4 viewMat) const; 
    void sendProjMat(const glm::mat4 projMat) const; 
    void sendNormMat(const glm::mat4 normMat) const; 
    inline void sendMatrixs(const glm::mat4 viewMat, const glm::mat4 projMat, const glm::mat4 normMat) const {
        sendViewMat(viewMat);
        sendProjMat(projMat);
        sendNormMat(normMat);
    }

    inline void skyShader() {_Shader3.use(); _inUse = 3;}
    inline void triShader() {_Shader2.use(); _inUse = 2;}
    inline void plnShader() {_Shader1.use(); _inUse = 1;}

};