#include <SDL2/SDL.h>
#include <GL/gl.h>

int main(int argc, char* argv[]){

	SDL_Window* window = NULL;
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	} else {
		window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL);
		if( window == NULL ){
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		} else {

			SDL_GLContext glcont = SDL_GL_CreateContext(window);
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


				SDL_GL_SwapWindow(window);

                Uint64 rend = SDL_GetPerformanceCounter();


            }

			//Destroy context
			SDL_GL_DeleteContext(glcont);
		}
	}


	//Destroy window
	SDL_DestroyWindow( window );

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}