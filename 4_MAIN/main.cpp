#include "SDLWindowManager.hpp"
#include "Skybox.hpp"
#include "Scene.hpp"
#include "mesh.hpp"
#include "CamControl.hpp"
#include "GameControl.hpp"
#include "MyShader.hpp"
#include "InfPlane.hpp"


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
	//SkyBox init
	Skybox moonlight;
	//Camera Init
	Camera super8;
	//Sader Init
	MyShader shader;
	//Ground Init
	InfPlane grid;
	//Car Model
	Model car2000("../ressources/assets/car.obj");

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
		
		//

		lastUpdate = current;


		/* RENDERING LOOP */

		/******************
		 * RENDERING CODE *
		 *****************/
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);



		shader.plnShader();
		shader.sendViewMat(super8.getViewMatrix());
		shader.sendProjMat(projectionMatrix);
		grid.render();
		
		shader.skyShader() ;
		shader.sendViewMat(glm::mat4(glm::mat3(super8.getViewMatrix())));
		shader.sendProjMat(projectionMatrix);
		moonlight.display();

		shader.triShader();
		shader.sendViewMat(super8.getViewMatrix());
		shader.sendProjMat(projectionMatrix);
		car2000.Draw();

		wndwManager.swapBuffers();

		SDL_GetMouseState(&mouseX, &mouseY);
	}

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}