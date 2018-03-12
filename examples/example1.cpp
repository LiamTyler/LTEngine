#include "include/Progression.h"

using namespace std;

int main() {
    InitEngine();
    Window window("Example 1", 800, 600);

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

    GameObject* cube = new GameObject(Transform(glm::vec3(2, 0, -5)));
    GameObject* sphere = new GameObject(Transform(glm::vec3(-2, 0, -5)));

    Camera* camera = new Camera;
    camera->AddComponent<CameraController>(new CameraController(4, .005));
    camera->transform.position.z += 3;

    Background* background = new Background(glm::vec3(1, 0, 0));

    DirectionalLight* dirLight = new DirectionalLight;

    Scene scene;
    scene.AddGameObject(cube);
    scene.AddGameObject(sphere);
    scene.camera = camera;
    scene.background = background;
    scene.AddLight(dirLight);

    bool quit = false;
    window.SetRelativeMouse(true);
    while (!quit) {
        window.StartFrame();
        quit = input->HandleInput();
        if (input->KeyPressed(K_ESC))
            quit = true;

        float dt = window.GetDT();

        renderer->RenderScene(scene);

        window.EndFrame();
    }

    QuitEngine();
    return 0;
}
