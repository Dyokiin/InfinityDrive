#include "../include/MyShader.hpp"

MyShader::MyShader(){

    std::string path = SDL_GetBasePath();
    
    _Shader1 = loadProgram(path + "../ressources/shaders/vertshade.vs.glsl",
                           path + "../ressources/shaders/fragshade.fs.glsl");
    // _Shader1 = loadProgram(path + "../ressources/shaders/triangle.vs.glsl",
    //                        path + "../ressources/shaders/triangle.fs.glsl");

    _Shader1.use();

    char uViewMat[] = "uViewMatrix";
    _uniformViewMat = glGetUniformLocation(_Shader1.getGLId(), (const GLchar*)uViewMat);

    char uProjMat[] = "uProjMatrix";
    _uniformProjMat = glGetUniformLocation(_Shader1.getGLId(), (const GLchar*)uProjMat);

    char uNormMat[] = "uNormMatrix";
    _uniformNormMat = glGetUniformLocation(_Shader1.getGLId(), (const GLchar*)uNormMat);
}
