#include "../include/GameControl.hpp"

DIRECTION GameUpdate(SDL_Event e){
    DIRECTION returnValue = KEEP;
    if(e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym)
        {
        case SDLK_z: case SDLK_UP:
            returnValue = JUMP;
            break;
        case SDLK_q: case SDLK_LEFT:
            returnValue = LEFT;
            break;
        case SDLK_d : case SDLK_RIGHT:
            returnValue = RIGHT;
            break;
        default:
            break;
        }
    }
    return returnValue;
}