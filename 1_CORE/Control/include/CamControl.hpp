#include <SDL2/SDL.h>
#include "../../../2_VISU/Camera/include/Camera.hpp"


// Allows camera mouvements troughtout mouse and toggle cam edit mode
bool camUpdate(Camera cam, SDL_Event e);


// Allows camera mouvements with arrow keys and toggle first person cam
void camControl(Camera cam, SDL_Keycode code);