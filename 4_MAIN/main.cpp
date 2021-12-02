#include "SDLWindowManager.hpp"
#include "Skybox.hpp"
#include "Scene.hpp"
#include "CamControl.hpp"
#include "GameControl.hpp"
#include "MyShader.hpp"
#include "InfPlane.hpp"


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

	//Several variables useful to the main loop
	bool quit = false;
	bool camSetUp = true;

	Uint32 lastUpdate = SDL_GetTicks();
	SDL_Event e;

	//Mouse state 
	int mouseX, mouseY;

	/*************TEST CODE : JUST SOMETHING PLEASE***********/

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	std::vector<ShapeVertexTex> vertices = {ShapeVertexTex(glm::vec3(-0.5,0,0.), glm::vec3(1.,0.,0.), glm::vec2(0)),
											ShapeVertexTex(glm::vec3( 0.5,0,0.), glm::vec3(0.,1.,0.), glm::vec2(0)),
											ShapeVertexTex(glm::vec3( 0. ,1,0.), glm::vec3(0.,0.,1.), glm::vec2(0))};
    glBufferData(GL_ARRAY_BUFFER, 3*sizeof(ShapeVertexTex), &vertices[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    const GLuint VERTEX_ATTR_POSITION = 3;
    glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
    const GLuint VERTEX_ATTR_COLOR = 8;
    glEnableVertexAttribArray(VERTEX_ATTR_COLOR);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertexTex), 0);
    glVertexAttribPointer(VERTEX_ATTR_COLOR, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertexTex), (const GLvoid*)(sizeof(glm::vec3)));   
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

	// glm::mat4 view = glm::mat4(1.0f);
    // view = glm::mat4(glm::mat3(glm::lookAt(_camera._position, _camera._position + _camera._orientation, _camera._up)));
    // glm::mat4 projection = glm::mat4(1.0f);
    // projection = glm::perspective(glm::radians(45.0f), (float)_width / _height, 0.1f, 100.0f);
    // glUniformMatrix4fv(glGetUniformLocation(_skyboxShader._id, "view"), 1, GL_FALSE, glm::value_ptr(view));
    // glUniformMatrix4fv(glGetUniformLocation(_skyboxShader._id, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

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

		shader.triShader();
		shader.sendViewMat(super8.getViewMatrix());
		shader.sendProjMat(projectionMatrix);

		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);

		
		shader.skyShader() ;
		shader.sendViewMat(super8.getViewMatrix());
		shader.sendProjMat(projectionMatrix);

		moonlight.display();

		wndwManager.swapBuffers();

		SDL_GetMouseState(&mouseX, &mouseY);
	}

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}