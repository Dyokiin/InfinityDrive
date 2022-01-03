#include "SDLWindowManager.hpp"
#include "Model.hpp"
#include "Scene.hpp"
#include "CamControl.hpp"
#include "GameControl.hpp"
#include "TtfManager.hpp"
#include "Menu.hpp"

#include <GL/gl.h>

#define WINDOW_WIDTH 1500
#define WINDOW_HEIGHT 1000


int main(int argc, char* argv[]){

	/********************* INITIALISATION ********************/

	//Window init : fixed size
	SDLWindowManager wndwManager(WINDOW_WIDTH, WINDOW_HEIGHT, "Infinity Drive");
	glewInit();
	//Projection Matrix : fixed window size
	glm::mat4 projectionMatrix = glm::perspective(glm::radians(90.f),
												  (float)WINDOW_WIDTH/(float)WINDOW_HEIGHT,
												  0.5f, 200.f);
	//SDL_TTF init and menu init
	//TODO: Menu 2D shader
	Menu menu;
	try{
		SDL_Color color;
		color.r = 255;
		color.g = 255;
		color.b = 255;
		TtfManager printer(30, "../ressources/MMDR.ttf", color);
		menu.init(printer);
	}
	catch(...){
		std::cerr << "Switching to non-dynamic text" << std::endl;
		menu.init();
	}


	//Camera Init
	Camera super8;

	//Scene Init
	Scene mainScene;
	mainScene.init(super8);

	//Several variables useful to the main loop
	bool quit = false;
	bool camSetUp = true;

	DIRECTION lastInput = KEEP;

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
				} else if(e.type == SDL_KEYDOWN){
					lastInput = GameUpdate(e);
				}
			}
		}

		/* ENGINE LOOP */

		Uint32 current = SDL_GetTicks();
		float dT = (current - lastUpdate) / 1000.0f;
		
		if(!camSetUp){
			if(lastInput == RESET){camSetUp=true;}
			mainScene.update(super8, dT, lastInput);

			lastUpdate = current;
		}

		/******************
		 * RENDERING CODE *
		 *****************/
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glDepthFunc(GL_LEQUAL);

		menu.display();

		mainScene.Draw(super8.getViewMatrix(), projectionMatrix, super8.getFP());

		wndwManager.swapBuffers();

		lastInput = KEEP;
	}

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}