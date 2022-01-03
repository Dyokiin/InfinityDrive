#include <SDL2/SDL.h>
#include "../../../2_VISU/Camera/include/Camera.hpp"


/// \brief Allows camera mouvements troughtout mouse and toggle cam edit mode
/// \param cam : Camera to update
/// \param e : SDL event to use
/// \param x : x coordinate of the mouse in the window 
/// \param y : y coordinate of the mouse in the window
bool camUpdate(Camera &cam, SDL_Event e, const int x,const int y);
