#include "../include/TtfManager.hpp"


TtfManager::TtfManager(const unsigned int size, std::string pathToFont, SDL_Color color){
    TTF_Init();
    _size = size;
    _colour = color;

    std::string path = SDL_GetBasePath() + pathToFont;
    _font = TTF_OpenFont(path.c_str(), _size);

    if(!_font){
        std::cerr << "Font not loaded : " << TTF_GetError() << std::endl;
        throw std::ios_base::failure("");
    }
}

TtfManager::~TtfManager(){
    TTF_CloseFont(_font);
    TTF_Quit();
}

SDL_Surface* TtfManager::getLabel(std::string text) const {
    SDL_Surface* Label = TTF_RenderText_Blended(_font, text.c_str(), _colour);
    return Label;
}
