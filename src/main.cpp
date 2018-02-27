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
#include "include/window.h"
#include "include/input.h"

using namespace std;

Renderer* renderer;

int main() {
    Window window("Starter Project", 800, 600);

    renderer = new Renderer;
    renderer->AddShader("meshShader", "shaders/regular_phong.vert",
            "shaders/regular_phong.frag", "");

    ResourceManager* resourceManager = new ResourceManager;
    Material cubeMat = Material(
            glm::vec4(1.0, .4, .4, 1),
            glm::vec4(1.0, .4, .4, 1),
            glm::vec4(.6, .6,  .6, 1),
            50);
    Material* mat1 = resourceManager->AllocateResource<Material>(cubeMat);
    Mesh* mesh = resourceManager->LoadMesh("models/sphere.obj");

    GameObject Bjorn = GameObject(Transform(), new MeshRenderer(mesh, mat1, "meshShader"));


    Camera camera = Camera(glm::vec3(0, 0, 5), glm::vec3(0, 0, -1), glm::vec3(0, 1, 0), 5, 0.005);
    Input input;

    bool quit = false;
    window.SetRelativeMouse(true);
    while (!quit) {
        window.StartFrame();
        quit = input.HandleInput();
        if (input.KeyPressed(K_W)) {
            camera.VelZ(1.0f);
        }
        if (input.KeyPressed(K_S)) {
            camera.VelZ(-1.0f);
        }
        if (input.KeyPressed(K_A)) {
            camera.VelX(-1.0f);
        }
        if (input.KeyPressed(K_D)) {
            camera.VelX(1.0f);
        }
        if (input.KeyPressed(K_ESC)) {
            quit = true;
        }
        if (input.KeyReleased(K_W))
            camera.VelZ(0);
        if (input.KeyReleased(K_S))
            camera.VelZ(0);
        if (input.KeyReleased(K_A))
            camera.VelX(0);
        if (input.KeyReleased(K_D))
            camera.VelX(0);

        if (input.MouseMotionEvent()) {
            camera.RotateX(-input.mouse.dy);
            camera.RotateY(-input.mouse.dx);
            camera.UpdateAxis();
        }

        float dt = window.GetDT();
        camera.Update(dt);

        renderer->RenderScene(camera);

        window.EndFrame();
    }

    // Clean up
    delete renderer;
    delete resourceManager;

    return 0;
}
