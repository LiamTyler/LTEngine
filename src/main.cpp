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
    Mesh* mesh = rm->LoadMesh("models/cube.obj");
    cout << "mesh tris: " << mesh->GetNumTriangles() << endl;

    GameObject Bjorn = GameObject(Transform(), new MeshRenderer(mesh, mat1, "mesh"));

    Camera camera = Camera(glm::vec3(0, 0, 5), glm::vec3(0, 0, -1), glm::vec3(0, 1, 0), 5, 0.005);

    Input input;

    bool quit = false;
    SDL_Event event;
    SDL_SetRelativeMouseMode(SDL_TRUE);
    FPSCounter fpsCounter;
    while (!quit) {
        input.HandleInput();
        if (input.KeyPressed(K_A))
            cout << "Pressed key: A" << endl;
        if (input.KeyPressed(K_B))
            cout << "Pressed key: B" << endl;
        if (input.KeyPressed(K_C))
            cout << "Pressed key: C" << endl;
        if (input.KeyPressed(K_D))
            cout << "Pressed key: D" << endl;
        if (input.KeyPressed(K_E))
            cout << "Pressed key: E" << endl;
        if (input.KeyPressed(K_F))
            cout << "Pressed key: F" << endl;
        if (input.KeyPressed(K_G))
            cout << "Pressed key: G" << endl;
        if (input.KeyPressed(K_H))
            cout << "Pressed key: H" << endl;
        if (input.KeyPressed(K_I))
            cout << "Pressed key: I" << endl;
        if (input.KeyPressed(K_J))
            cout << "Pressed key: J" << endl;
        if (input.KeyPressed(K_K))
            cout << "Pressed key: K" << endl;
        if (input.KeyPressed(K_L))
            cout << "Pressed key: L" << endl;
        if (input.KeyPressed(K_M))
            cout << "Pressed key: M" << endl;
        if (input.KeyPressed(K_N))
            cout << "Pressed key: N" << endl;
        if (input.KeyPressed(K_O))
            cout << "Pressed key: O" << endl;
        if (input.KeyPressed(K_P))
            cout << "Pressed key: P" << endl;
        if (input.KeyPressed(K_Q))
            cout << "Pressed key: Q" << endl;
        if (input.KeyPressed(K_R))
            cout << "Pressed key: R" << endl;
        if (input.KeyPressed(K_S))
            cout << "Pressed key: S" << endl;
        if (input.KeyPressed(K_T))
            cout << "Pressed key: T" << endl;
        if (input.KeyPressed(K_U))
            cout << "Pressed key: U" << endl;
        if (input.KeyPressed(K_V))
            cout << "Pressed key: V" << endl;
        if (input.KeyPressed(K_W))
            cout << "Pressed key: W" << endl;
        if (input.KeyPressed(K_X))
            cout << "Pressed key: X" << endl;
        if (input.KeyPressed(K_Y))
            cout << "Pressed key: Y" << endl;
        if (input.KeyPressed(K_Z))
            cout << "Pressed key: Z" << endl;
        if (input.KeyPressed(K_ESC))
            cout << "Pressed key: ESC" << endl;
        if (input.KeyPressed(K_F1))
            cout << "Pressed key: F1" << endl;
        if (input.KeyPressed(K_F2))
            cout << "Pressed key: F2" << endl;
        if (input.KeyPressed(K_F3))
            cout << "Pressed key: F3" << endl;
        if (input.KeyPressed(K_F4))
            cout << "Pressed key: F4" << endl;
        if (input.KeyPressed(K_F5))
            cout << "Pressed key: F5" << endl;
        if (input.KeyPressed(K_F6))
            cout << "Pressed key: F6" << endl;
        if (input.KeyPressed(K_F7))
            cout << "Pressed key: F7" << endl;
        if (input.KeyPressed(K_F8))
            cout << "Pressed key: F8" << endl;
        if (input.KeyPressed(K_F9))
            cout << "Pressed key: F9" << endl;
        if (input.KeyPressed(K_F10))
            cout << "Pressed key: F10" << endl;
        if (input.KeyPressed(K_F11))
            cout << "Pressed key: F11" << endl;
        if (input.KeyPressed(K_F12))
            cout << "Pressed key: F12" << endl;
        if (input.KeyPressed(K_PRINTSCREEN))
            cout << "Pressed key: Prt screen" << endl;
        if (input.KeyPressed(K_INSERT))
            cout << "Pressed key: insert" << endl;
        if (input.KeyPressed(K_DELETE))
            cout << "Pressed key: delete" << endl;
        if (input.KeyPressed(K_HOME))
            cout << "Pressed key: home" << endl;
        if (input.KeyPressed(K_END))
            cout << "Pressed key: end" << endl;
        if (input.KeyPressed(K_PAGEUP))
            cout << "Pressed key: pageup" << endl;
        if (input.KeyPressed(K_PAGEDOWN))
            cout << "Pressed key: pagedown" << endl;
        if (input.KeyPressed(K_BACKQUOTE))
            cout << "Pressed key: backquote" << endl;
        if (input.KeyPressed(K_1))
            cout << "Pressed key: 1" << endl;
        if (input.KeyPressed(K_2))
            cout << "Pressed key: 2" << endl;
        if (input.KeyPressed(K_3))
            cout << "Pressed key: 3" << endl;
        if (input.KeyPressed(K_4))
            cout << "Pressed key: 4" << endl;
        if (input.KeyPressed(K_5))
            cout << "Pressed key: 5" << endl;
        if (input.KeyPressed(K_6))
            cout << "Pressed key: 6" << endl;
        if (input.KeyPressed(K_7))
            cout << "Pressed key: 7" << endl;
        if (input.KeyPressed(K_8))
            cout << "Pressed key: 8" << endl;
        if (input.KeyPressed(K_9))
            cout << "Pressed key: 9" << endl;
        if (input.KeyPressed(K_0))
            cout << "Pressed key: 0" << endl;
        if (input.KeyPressed(K_MINUS))
            cout << "Pressed key: minus" << endl;
        if (input.KeyPressed(K_EQUALS))
            cout << "Pressed key: equals" << endl;
        if (input.KeyPressed(K_BACKSPACE))
            cout << "Pressed key: backspace" << endl;
        if (input.KeyPressed(K_TAB))
            cout << "Pressed key: tab" << endl;
        if (input.KeyPressed(K_LBRACKET))
            cout << "Pressed key: [" << endl;
        if (input.KeyPressed(K_RBRACKET))
            cout << "Pressed key: ]" << endl;
        if (input.KeyPressed(K_BACKSLASH))
            cout << "Pressed key: backslash" << endl;
        if (input.KeyPressed(K_CAPSLOCK))
            cout << "Pressed key: capslock" << endl;
        if (input.KeyPressed(K_SEMICOLON))
            cout << "Pressed key: semicolon" << endl;
        if (input.KeyPressed(K_QUOTE))
            cout << "Pressed key: QUOTE" << endl;
        if (input.KeyPressed(K_ENTER))
            cout << "Pressed key: enter" << endl;
        if (input.KeyPressed(K_LSHIFT))
            cout << "Pressed key: lshift" << endl;
        if (input.KeyPressed(K_COMMA))
            cout << "Pressed key: cmoma" << endl;
        if (input.KeyPressed(K_PERIOD))
            cout << "Pressed key: period" << endl;
        if (input.KeyPressed(K_SLASH))
            cout << "Pressed key: SLASH" << endl;
        if (input.KeyPressed(K_RSHIFT))
            cout << "Pressed key: rshift" << endl;
        if (input.KeyPressed(K_LCONTROL))
            cout << "Pressed key: lcontrol" << endl;
        if (input.KeyPressed(K_SUPER))
            cout << "Pressed key: super" << endl;
        if (input.KeyPressed(K_LALT))
            cout << "Pressed key: lalt" << endl;
        if (input.KeyPressed(K_SPACE))
            cout << "Pressed key: space" << endl;
        if (input.KeyPressed(K_RALT))
            cout << "Pressed key: ralt" << endl;
        if (input.KeyPressed(K_MENU))
            cout << "Pressed key: menu" << endl;
        if (input.KeyPressed(K_RCONTROL))
            cout << "Pressed key: rcontrol" << endl;
        if (input.KeyPressed(K_LEFT))
            cout << "Pressed key: left" << endl;
        if (input.KeyPressed(K_RIGHT))
            cout << "Pressed key: right" << endl;
        if (input.KeyPressed(K_UP))
            cout << "Pressed key: UP" << endl;
        if (input.KeyPressed(K_DOWN))
            cout << "Pressed key: down" << endl;


        if (input.KeyReleased(K_A))
            cout << "Released key: A" << endl;
        if (input.KeyReleased(K_B))
            cout << "Released key: B" << endl;
        if (input.KeyReleased(K_C))
            cout << "Released key: C" << endl;
        if (input.KeyReleased(K_D))
            cout << "Released key: D" << endl;
        if (input.KeyReleased(K_E))
            cout << "Released key: E" << endl;
        if (input.KeyReleased(K_F))
            cout << "Released key: F" << endl;
        if (input.KeyReleased(K_G))
            cout << "Released key: G" << endl;
        if (input.KeyReleased(K_H))
            cout << "Released key: H" << endl;
        if (input.KeyReleased(K_I))
            cout << "Released key: I" << endl;
        if (input.KeyReleased(K_J))
            cout << "Released key: J" << endl;
        if (input.KeyReleased(K_K))
            cout << "Released key: K" << endl;
        if (input.KeyReleased(K_L))
            cout << "Released key: L" << endl;
        if (input.KeyReleased(K_M))
            cout << "Released key: M" << endl;
        if (input.KeyReleased(K_N))
            cout << "Released key: N" << endl;
        if (input.KeyReleased(K_O))
            cout << "Released key: O" << endl;
        if (input.KeyReleased(K_P))
            cout << "Released key: P" << endl;
        if (input.KeyReleased(K_Q))
            cout << "Released key: Q" << endl;
        if (input.KeyReleased(K_R))
            cout << "Released key: R" << endl;
        if (input.KeyReleased(K_S))
            cout << "Released key: S" << endl;
        if (input.KeyReleased(K_T))
            cout << "Released key: T" << endl;
        if (input.KeyReleased(K_U))
            cout << "Released key: U" << endl;
        if (input.KeyReleased(K_V))
            cout << "Released key: V" << endl;
        if (input.KeyReleased(K_W))
            cout << "Released key: W" << endl;
        if (input.KeyReleased(K_X))
            cout << "Released key: X" << endl;
        if (input.KeyReleased(K_Y))
            cout << "Released key: Y" << endl;
        if (input.KeyReleased(K_Z))
            cout << "Released key: Z" << endl;
        if (input.KeyReleased(K_ESC))
            cout << "Released key: ESC" << endl;
        if (input.KeyReleased(K_F1))
            cout << "Released key: F1" << endl;
        if (input.KeyReleased(K_F2))
            cout << "Released key: F2" << endl;
        if (input.KeyReleased(K_F3))
            cout << "Released key: F3" << endl;
        if (input.KeyReleased(K_F4))
            cout << "Released key: F4" << endl;
        if (input.KeyReleased(K_F5))
            cout << "Released key: F5" << endl;
        if (input.KeyReleased(K_F6))
            cout << "Released key: F6" << endl;
        if (input.KeyReleased(K_F7))
            cout << "Released key: F7" << endl;
        if (input.KeyReleased(K_F8))
            cout << "Released key: F8" << endl;
        if (input.KeyReleased(K_F9))
            cout << "Released key: F9" << endl;
        if (input.KeyReleased(K_F10))
            cout << "Released key: F10" << endl;
        if (input.KeyReleased(K_F11))
            cout << "Released key: F11" << endl;
        if (input.KeyReleased(K_F12))
            cout << "Released key: F12" << endl;
        if (input.KeyReleased(K_PRINTSCREEN))
            cout << "Released key: Prt screen" << endl;
        if (input.KeyReleased(K_INSERT))
            cout << "Released key: insert" << endl;
        if (input.KeyReleased(K_DELETE))
            cout << "Released key: delete" << endl;
        if (input.KeyReleased(K_HOME))
            cout << "Released key: home" << endl;
        if (input.KeyReleased(K_END))
            cout << "Released key: end" << endl;
        if (input.KeyReleased(K_PAGEUP))
            cout << "Released key: pageup" << endl;
        if (input.KeyReleased(K_PAGEDOWN))
            cout << "Released key: pagedown" << endl;
        if (input.KeyReleased(K_BACKQUOTE))
            cout << "Released key: backquote" << endl;
        if (input.KeyReleased(K_1))
            cout << "Released key: 1" << endl;
        if (input.KeyReleased(K_2))
            cout << "Released key: 2" << endl;
        if (input.KeyReleased(K_3))
            cout << "Released key: 3" << endl;
        if (input.KeyReleased(K_4))
            cout << "Released key: 4" << endl;
        if (input.KeyReleased(K_5))
            cout << "Released key: 5" << endl;
        if (input.KeyReleased(K_6))
            cout << "Released key: 6" << endl;
        if (input.KeyReleased(K_7))
            cout << "Released key: 7" << endl;
        if (input.KeyReleased(K_8))
            cout << "Released key: 8" << endl;
        if (input.KeyReleased(K_9))
            cout << "Released key: 9" << endl;
        if (input.KeyReleased(K_0))
            cout << "Released key: 0" << endl;
        if (input.KeyReleased(K_MINUS))
            cout << "Released key: minus" << endl;
        if (input.KeyReleased(K_EQUALS))
            cout << "Released key: equals" << endl;
        if (input.KeyReleased(K_BACKSPACE))
            cout << "Released key: backspace" << endl;
        if (input.KeyReleased(K_TAB))
            cout << "Released key: tab" << endl;
        if (input.KeyReleased(K_LBRACKET))
            cout << "Released key: [" << endl;
        if (input.KeyReleased(K_RBRACKET))
            cout << "Released key: ]" << endl;
        if (input.KeyReleased(K_BACKSLASH))
            cout << "Released key: backslash" << endl;
        if (input.KeyReleased(K_CAPSLOCK))
            cout << "Released key: capslock" << endl;
        if (input.KeyReleased(K_SEMICOLON))
            cout << "Released key: semicolon" << endl;
        if (input.KeyReleased(K_QUOTE))
            cout << "Released key: QUOTE" << endl;
        if (input.KeyReleased(K_ENTER))
            cout << "Released key: enter" << endl;
        if (input.KeyReleased(K_LSHIFT))
            cout << "Released key: lshift" << endl;
        if (input.KeyReleased(K_COMMA))
            cout << "Released key: cmoma" << endl;
        if (input.KeyReleased(K_PERIOD))
            cout << "Released key: period" << endl;
        if (input.KeyReleased(K_SLASH))
            cout << "Released key: SLASH" << endl;
        if (input.KeyReleased(K_RSHIFT))
            cout << "Released key: rshift" << endl;
        if (input.KeyReleased(K_LCONTROL))
            cout << "Released key: lcontrol" << endl;
        if (input.KeyReleased(K_SUPER))
            cout << "Released key: super" << endl;
        if (input.KeyReleased(K_LALT))
            cout << "Released key: lalt" << endl;
        if (input.KeyReleased(K_SPACE))
            cout << "Released key: space" << endl;
        if (input.KeyReleased(K_RALT))
            cout << "Released key: ralt" << endl;
        if (input.KeyReleased(K_MENU))
            cout << "Released key: menu" << endl;
        if (input.KeyReleased(K_RCONTROL))
            cout << "Released key: rcontrol" << endl;
        if (input.KeyReleased(K_LEFT))
            cout << "Released key: left" << endl;
        if (input.KeyReleased(K_RIGHT))
            cout << "Released key: right" << endl;
        if (input.KeyReleased(K_UP))
            cout << "Released key: UP" << endl;
        if (input.KeyReleased(K_DOWN))
            cout << "Released key: down" << endl;
        /*
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
        if (input.KeyPressed(K_E)) {
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
        */
        /*
            } else if (event.type == SDL_MOUSEMOTION) {
                // handle mouse events
                float dx = event.motion.xrel;
                float dy = event.motion.yrel;
                camera.RotateX(-dy);
                camera.RotateY(-dx);
                camera.UpdateAxis();
            }
        }
        */

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
