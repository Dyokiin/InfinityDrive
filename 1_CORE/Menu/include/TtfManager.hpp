#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <iostream>
#include <exception>

class TtfManager {
private:
    TTF_Font *_font;
    unsigned int _size;
    SDL_Color _colour;
    
public:
    TtfManager(const unsigned int size, std::string pathToFont, SDL_Color colour);
    ~TtfManager();

    inline void setColor(const SDL_Color color) {_colour = color;}
    inline SDL_Color getColor() const {return _colour;}
    inline void setSize(const unsigned int newSize) {_size = newSize;}
    inline unsigned int getSize() const {return _size;}

    SDL_Surface* getLabel(std::string text) const;
};