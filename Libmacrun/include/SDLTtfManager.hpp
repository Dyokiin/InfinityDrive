#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>

class Textext {
private:
    std::vector<char> _label;
    glm::vec2 _coords;
    GLuint _text;

public:

    Textext();
    Textext(const std::vector<char> label, const glm::vec2 coords);

    ~Textext();

    void display() const;
    GLuint getTex() const; 
};