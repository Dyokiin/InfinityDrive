#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <iostream>
#include <string>

class Textext {
private:
    std::string _label;
    glm::vec2 _coords;
    GLuint _text;

public:

    Textext();
    Textext(const std::string label, const glm::vec2 &coords, TTF_Font* police);

    ~Textext();

    void displayOnScreen() const;
    inline GLuint getTex() const {return _text;} 
};

TTF_Font* TTFManagerInit();
void TTFManagerQuit(TTF_Font* police);