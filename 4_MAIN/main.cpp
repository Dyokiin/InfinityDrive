#include "SDLWindowManager.hpp"
#include "Model.hpp"
#include "Scene.hpp"
#include "CamControl.hpp"
#include "GameControl.hpp"

#include <GL/gl.h>

#define WINDOW_WIDTH 1500
#define WINDOW_HEIGHT 1000


int main(int argc, char* argv[]){

	/********************* INITIALISATION ********************/

	//Window init : fixed size
	SDLWindowManager wndwManager(WINDOW_WIDTH, WINDOW_HEIGHT, "VroomRun");
	glewInit();
	//Projection Matrix : fixed window size
	glm::mat4 projectionMatrix = glm::perspective(glm::radians(90.f),
												  (float)WINDOW_WIDTH/(float)WINDOW_HEIGHT,
												  0.001f, 200.f);
	//Scene Init
	Scene mainScene;
	mainScene.init();

	//Camera Init
	Camera super8;


	//Several variables useful to the main loop
	bool quit = false;
	bool camSetUp = true;

	Uint32 lastUpdate = SDL_GetTicks();
	SDL_Event e;

	//Mouse state 
	int mouseX, mouseY;

	/************************ MAIN LOOP **********************/

	while(!quit){

		/* INPUT LOOP */
		if(camSetUp){
			SDL_GetMouseState(&mouseX, &mouseY);
			while(SDL_PollEvent(&e) != 0){
				if(e.type == SDL_QUIT){
					quit = true;
				} else {
					camSetUp = camUpdate(super8, e, mouseX, mouseY);
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

		/* ENGINE LOOP */

		Uint32 current = SDL_GetTicks();
		float dT = (current - lastUpdate) / 1000.0f;
		
		if(!camSetUp){
			mainScene.update(super8);

			lastUpdate = current;
		}


		/******************
		 * RENDERING CODE *
		 *****************/
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);

		mainScene.Draw(super8.getViewMatrix(), projectionMatrix);

		wndwManager.swapBuffers();
	}

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}