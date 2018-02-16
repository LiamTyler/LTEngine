#include "include/utils.h"
#include "include/camera.h"
#include "include/fps_counter.h"
#include "include/mesh.h"
#include "include/scene.h"
#include "include/renderer.h"
#include "include/game_object.h"
#include "include/material.h"
#include <assert.h>

using namespace std;

int main(int arc, char** argv) {
    // initialize SDL and GLEW and set up window
    SDL_Window* window = InitAndWindow("Starter Project", 100, 100, 800, 600);
    cout << "vendor: " << glGetString(GL_VENDOR) << endl;
    cout << "renderer: " << glGetString(GL_RENDERER) << endl;
    cout << "version: " << glGetString(GL_VERSION) << endl;
    Material cubeMat = Material(
            vec3(1.0, .4, .4),
            vec3(1.0, .4, .4),
            vec3(.6, .6, .6),
            50);
    Light light = Light(
            normalize(vec3(-1, -.5, -.8)),
            vec3(.3, .3, .3),
            vec3(.7, .7, .7),
            vec3(1.0, 1.0, 1.0));

    // set up the particle system
    Camera camera = Camera(vec3(0, 0, 5), vec3(0, 0, -1), vec3(0, 1, 0), 5, 0.005);

    GameObject* cube = new GameObject;
    Mesh mesh("models/cube.obj", 0);
    mesh.SetMaterial(cubeMat);
    cube->SetMesh(&mesh);

    Scene scene;
    scene.AddObject(cube);
    scene.SetCamera(&camera);
    scene.SetLight(light);

    Renderer renderer;
    renderer.Init();
    renderer.LoadScene(&scene);

    bool quit = false;
    SDL_Event event;
    SDL_SetRelativeMouseMode(SDL_TRUE);
    FPSCounter fpsC;
    fpsC.Init();
    while (!quit) {
        // Process all input events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            } else if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
                // key down events (wont repeat if holding key down)
                switch (event.key.keysym.sym) {
                    case SDLK_w:
                        camera.VelZ(1.0f);
                        break;
                    case SDLK_s:
                        camera.VelZ(-1.0f);
                        break;
                    case SDLK_a:
                        camera.VelX(-1.0f);
                        break;
                    case SDLK_d:
                        camera.VelX(1.0f);
                        break;
                    case SDLK_ESCAPE:
                        quit = true;
                        break;
                    case SDLK_p:
                        break;
                    case SDLK_SPACE:
                        break;
                }
            } else if (event.type == SDL_KEYUP) {
                // handle key up events
                switch (event.key.keysym.sym) {
                    case SDLK_w:
                    case SDLK_s:
                        camera.VelZ(0.0f);
                        break;
                    case SDLK_a:
                    case SDLK_d:
                        camera.VelX(0.0f);
                        break;
                    case SDLK_SPACE:
                        break;
                }
            } else if (event.type == SDL_MOUSEMOTION) {
                // handle mouse events
                float dx = event.motion.xrel;
                float dy = event.motion.yrel;
                camera.RotateX(-dy);
                camera.RotateY(-dx);
                camera.UpdateAxis();
            }
        }

        float t = SDL_GetTicks() / 1000.0f;
        fpsC.StartFrame(t);
        float dt = fpsC.GetDT();
        camera.Update(dt);

        renderer.RenderScene(&scene);

        fpsC.EndFrame();

        SDL_GL_SwapWindow(window);
    }

    // Clean up
    SDL_Quit();

    return 0;
}
