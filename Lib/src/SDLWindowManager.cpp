#include "../include/SDLWindowManager.hpp"
#include <iostream>

SDLWindowManager::SDLWindowManager(uint32_t width, uint32_t height, const char* title) {
    if(0 != SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << SDL_GetError() << std::endl;
        return;
    }
    _window = SDL_CreateWindow(title , SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1500, 1000, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if(_window == NULL) {
        std::cerr << SDL_GetError() << std::endl;
        return;
    }
    _glcont = SDL_GL_CreateContext(_window);
}

SDLWindowManager::~SDLWindowManager() {
    SDL_GL_DeleteContext(_glcont);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

bool SDLWindowManager::pollEvent(SDL_Event& e) {
    return SDL_PollEvent(&e);
}

// button can SDL_BUTTON_LEFT, SDL_BUTTON_RIGHT and SDL_BUTTON_MIDDLE
bool SDLWindowManager::isMouseButtonPressed(uint32_t button) const {
    return SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON(button);
}

glm::ivec2 SDLWindowManager::getMousePosition() const {
    glm::ivec2 mousePos;
    SDL_GetMouseState(&mousePos.x, &mousePos.y);
    return mousePos;
}

void SDLWindowManager::swapBuffers() {
    SDL_GL_SwapWindow(_window);
}

float SDLWindowManager::getTime() const {
    return 0.001f * SDL_GetTicks();
}