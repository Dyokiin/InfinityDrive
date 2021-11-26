#include "../include/CamControl.hpp"

bool camUpdate(Camera cam, SDL_Event e){

    float deltaX = 0;
    float deltaY = 0;

    bool returnValue = true;

    switch (e.type) {

        case SDL_KEYDOWN :

            if(e.key.keysym.sym == SDLK_c){
                returnValue = false;

            } else {
                camControl(cam, e.key.keysym.sym);
            }
            break;

        case SDL_MOUSEMOTION :

            deltaX += e.motion.x;
            deltaY += e.motion.y;

            cam.rotateLeft(deltaY);
            cam.rotateUp(deltaX);
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