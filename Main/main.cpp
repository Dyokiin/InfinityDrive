#include "SDLTtfManager.hpp"
#include "SDLWindowManager.hpp"

#include <SDL2/SDL.h>
#include <GL/gl.h>

int main(int argc, char* argv[]){

	SDLWindowManager wndwManager(1000, 800, "IMACrun");
	bool quit = false;
	Uint32 lastUpdate = SDL_GetTicks();
	SDL_Event e;


	while(!quit){

		Uint64 start = SDL_GetPerformanceCounter();


		/* INPUT LOOP */

		while(SDL_PollEvent(&e) != 0){
			switch(e.type){
			case SDL_QUIT:
				quit=true;
				break;
			case SDL_MOUSEBUTTONDOWN: {
				break;
				}
			default:
				break;
			}
		}

		Uint64 event = SDL_GetPerformanceCounter();

		/* ENGINE LOOP */

		Uint32 current = SDL_GetTicks();
		float dT = (current - lastUpdate) / 1000.0f;
		
		//

		lastUpdate = current;
		Uint64 phys = SDL_GetPerformanceCounter();


		/* RENDERING LOOP */

		/******************
		 * RENDERING CODE *
		 *****************/


		wndwManager.swapBuffers();

		Uint64 rend = SDL_GetPerformanceCounter();


	}

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}