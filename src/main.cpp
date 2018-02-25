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
    Window* window = new Window("Starter Project", 800, 600);

    renderer = new Renderer;
    renderer->AddShader("mesh", "shaders/regular_phong.vert",
            "shaders/regular_phong.frag", "");
    Shader* shader = renderer->GetShader("mesh");
    GLuint prgm = shader->GetProgram();
    GLint i;
    GLint count;
    GLint size;
    GLenum type;
    const GLsizei bufSize = 30;
    GLchar name[bufSize];
    GLsizei length;
    glGetProgramiv(prgm, GL_ACTIVE_ATTRIBUTES, &count);
    cout << "Active attributes: " << count << endl;
    for (i = 0; i < count; i++) {
        glGetActiveAttrib(prgm, (GLuint) i, bufSize, &length, &size, &type, name);
        cout << "\tAttrib: " << i << ", name: " << name << endl;
    }
    glGetProgramiv(prgm, GL_ACTIVE_UNIFORMS, &count);
    cout << "Active uniforms: " << count << endl;
    for (i = 0; i < count; i++) {
        glGetActiveUniform(prgm, (GLuint) i, bufSize, &length, &size, &type, name);
        cout << "\tUniform: " << i << ", name: " << name << endl;
    }
    glGetProgramiv(prgm, GL_ACTIVE_UNIFORM_BLOCKS, &count);
    cout << "Active uniform blocks: " << count << endl;
    for (i = 0; i < count; i++) {
        GLint nameLen;
        glGetActiveUniformBlockiv(prgm, i, GL_UNIFORM_BLOCK_NAME_LENGTH, &nameLen);
        std::vector<GLchar> name(nameLen);
        glGetActiveUniformBlockName(prgm, i, nameLen, NULL, &name[0]);
        std::string sName;
        sName.assign(name.begin(), name.end() - 1);

        cout << "\t: Uniform Block: " << i << ", name: " << sName << endl;
    }

    ResourceManager* rm = new ResourceManager;
    Material cubeMat = Material(
            glm::vec4(1.0, .4, .4, 1),
            glm::vec4(1.0, .4, .4, 1),
            glm::vec4(.6, .6,  .6, 1),
            50);
    Material* mat1 = rm->AllocateResource<Material>(cubeMat);
    Mesh* mesh = rm->LoadMesh("models/sphere.obj");
    cout << "mesh tris: " << mesh->GetNumTriangles() << endl;

    GameObject Bjorn = GameObject(Transform(), new MeshRenderer(mesh, mat1, "mesh"));

    Camera camera = Camera(glm::vec3(0, 0, 5), glm::vec3(0, 0, -1), glm::vec3(0, 1, 0), 5, 0.005);

    Input input;

    bool quit = false;
    SDL_Event event;
    window->SetRelativeMouse(true);
    FPSCounter fpsCounter;
    while (!quit) {
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

        float t = SDL_GetTicks() / 1000.0f;
        fpsCounter.StartFrame(t);
        float dt = fpsCounter.GetDT();
        camera.Update(dt);

        renderer->RenderScene(camera);

        fpsCounter.EndFrame();

        window->SwapWindow();
    }

    // Clean up
    SDL_Quit();

    return 0;
}
