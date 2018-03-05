#include "include/Progression.h"

using namespace std;

int main() {
    InitEngine();
    Window window("Starter Project", 800, 600);

    Material* redMat = resourceManager->AllocateResource<Material>(Material(
            glm::vec4(1.0, .4, .4, 1),
            glm::vec4(1.0, .4, .4, 1),
            glm::vec4(.6, .6,  .6, 1),
            50));
    Material* blueMat = resourceManager->AllocateResource<Material>(Material(
            glm::vec4(.4, .4, 1.0, 1),
            glm::vec4(.4, .4, 1.0, 1),
            glm::vec4(.6, .6,  .6, 1),
            50));
    Mesh* cubeMesh = resourceManager->LoadMesh("models/cube.obj");
    Mesh* sphereMesh = resourceManager->LoadMesh("models/sphere.obj");

    GameObject cube = GameObject(Transform(glm::vec3(2, 0, -5)));
    cube.AddComponent<MeshRenderer>(new MeshRenderer(cubeMesh, redMat, "meshShader"));
    GameObject sphere = GameObject(Transform(glm::vec3(-2, 0, -5)));
    sphere.AddComponent<MeshRenderer>(new MeshRenderer(sphereMesh, blueMat, "meshShader"));

    Camera camera = Camera();
    camera.AddComponent<CameraController>(new CameraController(4, .005));
    camera.transform.position.z += 3;

    bool quit = false;
    window.SetRelativeMouse(true);
    while (!quit) {
        window.StartFrame();
        quit = input->HandleInput();
        if (input->KeyPressed(K_ESC))
            quit = true;

        float dt = window.GetDT();
        camera.Update(dt);
        cube.Update(dt);
        sphere.Update(dt);
        renderer->RenderScene(camera);

        window.EndFrame();
    }

    QuitEngine();
    return 0;
}
