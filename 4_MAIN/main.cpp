#include "SDLWindowManager.hpp"
#include "Skybox.hpp"
#include "Scene.hpp"
#include "CamControl.hpp"
#include "GameControl.hpp"
#include "MyShader.hpp"


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

	//Sader Init
	MyShader shader;
	//shader.sendProjMat(projectionMatrix);

	//Several variables useful to the main loop
	bool quit = false;
	bool camSetUp = true;

	Uint32 lastUpdate = SDL_GetTicks();
	SDL_Event e;

	/*************TEST CODE : JUST SOMETHING PLEASE***********/

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
    GLfloat vertices[] = {-0.5f, -0.5f, 1.f, 0.f, 0.f,
                           0.5f, -0.5f, 0.f, 1.f, 0.f,
                           0.0f,  0.5f, 0.f, 0.f, 1.f};
    glBufferData(GL_ARRAY_BUFFER, 15*sizeof(GLfloat), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    const GLuint VERTEX_ATTR_POSITION = 3;
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    const GLuint VERTEX_ATTR_COLOR = 8;
    glEnableVertexAttribArray(VERTEX_ATTR_COLOR);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, 5*sizeof(float), 0);
    glVertexAttribPointer(VERTEX_ATTR_COLOR, 3, GL_FLOAT, GL_FALSE, 5*sizeof(float), (const GLvoid*)(2*(sizeof(GLfloat))));   
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

	/************************ MAIN LOOP **********************/

	while(!quit){

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
		//shader.sendViewMat(super8.getViewMatrix());


		/* ENGINE LOOP */

		Uint32 current = SDL_GetTicks();
		float dT = (current - lastUpdate) / 1000.0f;
		
		//

		lastUpdate = current;


		/* RENDERING LOOP */

		/******************
		 * RENDERING CODE *
		 *****************/
		glClear(GL_COLOR_BUFFER_BIT);

		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);

		
		
		
		moonlight.display();

		wndwManager.swapBuffers();
	}

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}