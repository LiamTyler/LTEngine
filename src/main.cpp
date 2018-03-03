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
#include "include/camera_controller.h"

using namespace std;

Renderer* renderer;
Input* input;

int main() {
    Window window("Starter Project", 800, 600);
    input = new Input;
    renderer = new Renderer;
    ResourceManager* resourceManager = new ResourceManager;

    renderer->AddShader("meshShader", "shaders/regular_phong.vert",
            "shaders/regular_phong.frag", "");

    Material* cubeMat = resourceManager->AllocateResource<Material>(Material(
            glm::vec4(1.0, .4, .4, 1),
            glm::vec4(1.0, .4, .4, 1),
            glm::vec4(.6, .6,  .6, 1),
            50));
    Mesh* mesh = resourceManager->LoadMesh("models/sphere.obj");

    GameObject Bjorn = GameObject(Transform());
    Bjorn.AddComponent<MeshRenderer>(new MeshRenderer(mesh, cubeMat, "meshShader"));

    Camera camera = Camera();
    camera.AddComponent<CameraController>(new CameraController(4, .005));

    bool quit = false;
    window.SetRelativeMouse(true);
    while (!quit) {
        window.StartFrame();
        quit = input->HandleInput();
        if (input->KeyPressed(K_ESC)) {
            quit = true;
        }

        float dt = window.GetDT();
        camera.Update(dt);
        Bjorn.Update(dt);
        renderer->RenderScene(camera);

        window.EndFrame();
    }

    // Clean up
    delete renderer;
    delete resourceManager;

    return 0;
}
