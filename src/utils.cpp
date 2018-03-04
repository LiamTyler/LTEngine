#include "include/utils.h"
#include "include/renderer.h"
#include "include/input.h"
#include "include/resource_manager.h"

Renderer* renderer;
Input* input;
ResourceManager* resourceManager;

void InitEngine() {
    // Init SDL2
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Failed to init SDL" << std::endl;
        exit(EXIT_FAILURE);
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    input = nullptr;
    renderer = nullptr;
    resourceManager = nullptr;
}

void InitEngineAfterWindow() {
    if (input == nullptr) {
        input = new Input;
        renderer = new Renderer;
        resourceManager = new ResourceManager;
    }
}


void QuitEngine() {
    delete input;
    delete renderer;
    delete resourceManager;
    SDL_Quit();
}
