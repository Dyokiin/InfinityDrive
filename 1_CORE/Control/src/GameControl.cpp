#include "../include/GameControl.hpp"

DIRECTION GameUpdate(SDL_Event e){
    DIRECTION returnValue = KEEP;
    if(e.type == SDL_KEYDOWN) {
        switch (e.key.keysym.sym)
        {
        case SDLK_z: SDLK_UP:
            returnValue = JUMP;
            break;
        case SDLK_q: SDLK_LEFT:
            returnValue = LEFT;
            break;
        case SDLK_d : SDLK_RIGHT;
            returnValue = RIGHT;
            break;
        default:
            break;
        }
    }
    return returnValue;
}