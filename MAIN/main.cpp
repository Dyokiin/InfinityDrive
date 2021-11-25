#include "SDLWindowManager.hpp"
#include "Skybox.hpp"
#include "Camera.hpp"
#include "Scene.hpp"

#include <SDL2/SDL.h>
#include <GL/gl.h>

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 800


int main(int argc, char* argv[]){

	/* INITIALISATION */

	//Window init : fixed size
	SDLWindowManager wndwManager(WINDOW_WIDTH, WINDOW_HEIGHT, "VroomRun");

	//Projection Matrix : fixed window size
	glm::mat4 projectionMatrix = glm::perspective(glm::radians(60.f),
												  float(WINDOW_WIDTH)/WINDOW_HEIGHT,
												  0.1f, 100.f);
	
	//Scene Init
	Scene mainScene;
	mainScene.init();

	//SkyBox init
	Skybox moonlight;

	//Several variables useful to the main loop
	bool quit = false;
	Uint32 lastUpdate = SDL_GetTicks();
	SDL_Event e;


	/* MAIN LOOP */

	while(!quit){

		Uint64 start = SDL_GetPerformanceCounter();


		/* INPUT LOOP */

		while(SDL_PollEvent(&e) != 0){
			switch(e.type){
			case SDL_QUIT:
				quit=true;
				break;
			case SDL_MOUSEBUTTONDOWN: {
				quit=true;
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
		//voiture.render();

		wndwManager.swapBuffers();

		Uint64 rend = SDL_GetPerformanceCounter();


	}

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}