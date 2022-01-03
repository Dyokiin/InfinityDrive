#pragma once

#include "../include/Program.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <SDL2/SDL.h>

/// \class MyShader
/// \brief My implementation to use several shaders
class MyShader{
private:
    
    Program _Shader1;
    Program _Shader2;
    Program _Shader3;

    int _inUse;

public:
    
    MyShader();
    MyShader(const MyShader &shader)
    : _Shader1(shader._Shader1), _Shader2(shader._Shader2), _Shader3(shader._Shader3), _inUse(shader._inUse) {}
    ~MyShader() = default;

    void init();
    void use() const;

    void sendProjViewMat(const glm::mat4 viewMat) const; 
    void sendProjModelMat(const glm::mat4 projmodelMat) const; 
    void sendMVPMat(const glm::mat4 MVPMat) const;
    void sendNormalMat(const glm::mat4 ModelMat, const glm::mat4 ViewMat) const;
    void sendMaterials(const glm::vec3 Ks, const glm::vec3 Kd) const;

    inline void skyShader() {_Shader3.use(); _inUse = 3;}
    inline void triShader() {_Shader2.use(); _inUse = 2;}
    inline void plnShader() {_Shader1.use(); _inUse = 1;}

};