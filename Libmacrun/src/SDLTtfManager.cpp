#include "../include/SDLTtfManager.hpp"
#include <assert.h>


TTF_Font* TTFManagerInit(){

    if(TTF_Init() == -1){
        std::cerr << " Init TTF failed : " << TTF_GetError() << std::endl;
        exit(EXIT_FAILURE);
    }

    TTF_Font *police = NULL;

    std::string path = SDL_GetBasePath();
    path += "../../ressources/MajorMonoDisplay-Regular.ttf";

    police = TTF_OpenFont(path.c_str(), 65);

    if(police == NULL){
        std::cerr << "Font Load failed" << std::endl;
    }

    return police;
}


void TTFManagerQuit(TTF_Font* police){

    TTF_CloseFont(police);

    TTF_Quit();
}


Textext::Textext(const std::string label, const glm::vec2 &coords, TTF_Font* police){
    _coords = coords;
    _label = label;

    //Text Color : always white ? 
    SDL_Color texCol = {250,250,250};
    SDL_Surface* text = TTF_RenderText_Blended(police, label.c_str(), texCol);

    glGenTextures(1, &_text);
    glBindTexture(GL_TEXTURE_2D, _text);
    glTexImage2D(GL_TEXTURE_2D, 0, 4, text->w, text->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, text->pixels);
    glBindTexture(GL_TEXTURE_2D, 0);

    SDL_FreeSurface(text);
}


Textext::~Textext(){
    glDeleteTextures(1, &_text);
}


void Textext::displayOnScreen() const {
    //todo
}