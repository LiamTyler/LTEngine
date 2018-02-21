#include <iostream>
#include <unordered_map>
#include "include/rid.h"
#include "include/material.h"
#include "include/mesh.h"
#include "include/resource_manager.h"
#include "include/game_object.h"
#include "include/mesh_renderer.h"
#include "include/renderer.h"
#include "include/camera.h"
#include "include/fps_counter.h"

using namespace std;

Renderer* renderer;

int main() {
    SDL_Window* window = InitAndWindow("Starter Project", 100, 100, 800, 600);
    cout << "vendor: " << glGetString(GL_VENDOR) << endl;
    cout << "renderer: " << glGetString(GL_RENDERER) << endl;
    cout << "version: " << glGetString(GL_VERSION) << endl;

    renderer = new Renderer;
    renderer->AddShader("mesh", "shaders/regular_phong.vert",
            "shaders/regular_phong.frag", "");

    ResourceManager* rm = new ResourceManager;
    Material cubeMat = Material(
            glm::vec4(1.0, .4, .4, 1),
            glm::vec4(1.0, .4, .4, 1),
            glm::vec4(.6, .6,  .6, 1),
            50);
    Material* mat1 = rm->AllocateResource<Material>(cubeMat);
    Mesh* mesh = rm->LoadMesh("models/cube.obj");
    cout << "mesh tris: " << mesh->GetNumTriangles() << endl;

    GameObject Bjorn = GameObject(Transform(), new MeshRenderer(mesh, mat1, "mesh"));

    Camera camera = Camera(glm::vec3(0, 0, 5), glm::vec3(0, 0, -1), glm::vec3(0, 1, 0), 5, 0.005);

    bool quit = false;
    SDL_Event event;
    SDL_SetRelativeMouseMode(SDL_TRUE);
    FPSCounter fpsCounter;
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
        fpsCounter.StartFrame(t);
        float dt = fpsCounter.GetDT();
        camera.Update(dt);

        renderer->RenderScene(camera);

        fpsCounter.EndFrame();

        SDL_GL_SwapWindow(window);
    }

    // Clean up
    SDL_Quit();

    return 0;
}
