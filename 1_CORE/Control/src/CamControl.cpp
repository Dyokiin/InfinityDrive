#include "../include/CamControl.hpp"

#define MOUSE_SENSIVITY_X 5
#define MOUSE_SENSIVITY_Y 10

//Update camera position from keyboard imput : only during set-up phase
bool camUpdate(Camera &cam, SDL_Event e, const int x, const int y){

    bool returnValue = true;

    switch (e.type) {
        case SDL_KEYDOWN :

            if(e.key.keysym.sym == SDLK_c){
                returnValue = false;
            }
            break;

        case SDL_MOUSEMOTION :

            int mx,my;
            SDL_GetMouseState(&mx, &my);

            cam.rotateLeft((float)(y - my)/(float)MOUSE_SENSIVITY_Y);
            cam.rotateUp((float)(x - mx)/(float)MOUSE_SENSIVITY_X);

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