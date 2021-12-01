#include "../include/CamControl.hpp"
#include <iostream>

bool camUpdate(Camera &cam, SDL_Event e, const int x, const int y){

    bool returnValue = true;

    switch (e.type) {

        case SDL_KEYDOWN :

            if(e.key.keysym.sym == SDLK_c){
                returnValue = false;

            } else {
                //camControl(cam, e.key.keysym.sym);
            }
            break;

        case SDL_MOUSEMOTION :

            int mx,my;
            SDL_GetMouseState(&mx, &my);

            cam.rotateLeft((float)(y - my)/(float)10);
            cam.rotateUp((float)(x - mx)/(float)10);

            break;

        case SDL_MOUSEWHEEL :

            cam.moveFront(e.wheel.y);
            break;

        case SDL_MOUSEBUTTONDOWN :

            returnValue = false;
            break;

        default:
            break;
        }

    return returnValue;
}

void camControl(Camera cam, SDL_Keycode key){
    //TODO
}