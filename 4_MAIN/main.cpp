#include "SDLWindowManager.hpp"
#include "Skybox.hpp"
#include "Scene.hpp"
#include "CamControl.hpp"
#include "GameControl.hpp"

#include <GL/gl.h>

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 800


int main(int argc, char* argv[]){

	/********************* INITIALISATION ********************/

	//Window init : fixed size
	SDLWindowManager wndwManager(WINDOW_WIDTH, WINDOW_HEIGHT, "VroomRun");
	glewInit();

	//Projection Matrix : fixed window size
	glm::mat4 projectionMatrix = glm::perspective(glm::radians(60.f),
												  float(WINDOW_WIDTH)/WINDOW_HEIGHT,
												  0.1f, 100.f);
	
	//Scene Init
	Scene mainScene;
	mainScene.init();

	//SkyBox init
	Skybox moonlight;

	//Camera Init
	Camera super8;

	//Several variables useful to the main loop
	bool quit = false;
	bool camSetUp = true;

	Uint32 lastUpdate = SDL_GetTicks();
	SDL_Event e;


	/************************ MAIN LOOP **********************/

	while(!quit){

		Uint64 start = SDL_GetPerformanceCounter();


		/* INPUT LOOP */
		if(camSetUp){
			while(SDL_PollEvent(&e) != 0){
				if(e.type == SDL_QUIT){
					quit = true;
				} else {
					camSetUp = camUpdate(super8, e);
				}
			}
		} else {
			while(SDL_PollEvent(&e) != 0){
				if(e.type == SDL_QUIT){
					quit = true;
				} else {
					GameUpdate(e);
				}
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
		
		
		
		moonlight.display();

		wndwManager.swapBuffers();

		Uint64 rend = SDL_GetPerformanceCounter();


	}

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}