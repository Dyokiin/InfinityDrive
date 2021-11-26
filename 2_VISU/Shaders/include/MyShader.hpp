#pragma once

#include "../../../3_EXT_INCLUDES/include/Program.hpp"
#include <glm/glm.hpp>

class MyShader{
private:
    
    Program _Shader1;
    //Program _Shader2;

public:
    
    MyShader();
    ~MyShader() = default;

    void init();
    void use() const;
    void sendMatrices(const glm::mat4 viewMat, const glm::mat4 projMat) const;

};