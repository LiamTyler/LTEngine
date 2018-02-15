#include "include/utils.h"
#include "include/camera.h"
#include "include/glsl_shader.h"
#include "include/image.h"
#include "include/fps_counter.h"
#include "include/mesh.h"

using namespace std;

int main(int arc, char** argv) {
    // initialize SDL and GLEW and set up window
    SDL_Window* window = InitAndWindow("Starter Project", 100, 100, 800, 600);
    cout << "vendor: " << glGetString(GL_VENDOR) << endl;
    cout << "renderer: " << glGetString(GL_RENDERER) << endl;
    cout << "version: " << glGetString(GL_VERSION) << endl;

    // set up the particle system
    Camera camera = Camera(vec3(0, 0, 5), vec3(0, 0, -1), vec3(0, 1, 0), 5, 0.005);
    GLSLShader shader;
    shader.LoadFromFile(GL_VERTEX_SHADER,   "shaders/regular_phong.vert");
    shader.LoadFromFile(GL_FRAGMENT_SHADER, "shaders/regular_phong.frag");
    shader.CreateAndLinkProgram();
    shader.Enable();
    shader.AddAttribute("vertex");
    shader.AddAttribute("normal");
    shader.AddUniform("modelViewMatrix");
    shader.AddUniform("normalMatrix");
    shader.AddUniform("projectionMatrix");
    shader.AddUniform("ka");
    shader.AddUniform("kd");
    shader.AddUniform("ks");
    shader.AddUniform("Ia");
    shader.AddUniform("Id");
    shader.AddUniform("Is");
    shader.AddUniform("specular");
    shader.AddUniform("lightInEyeSpace");


    // Mesh mesh("models/key.obj", "key");
    Mesh mesh("models/cube.obj", "cube");
    GLuint vao;
    GLuint vbo[3];
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glGenBuffers(3, vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, mesh.numVertices * sizeof(vec3), mesh.vertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(shader["vertex"]);
    glVertexAttribPointer(shader["vertex"], 3, GL_FLOAT, GL_FALSE, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
    glBufferData(GL_ARRAY_BUFFER, mesh.numVertices * sizeof(vec3), mesh.normals, GL_STATIC_DRAW);
    glEnableVertexAttribArray(shader["normal"]);
    glVertexAttribPointer(shader["normal"], 3, GL_FLOAT, GL_FALSE, 0, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[2]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.numTriangles * sizeof(ivec3),
            mesh.indices, GL_STATIC_DRAW);

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

        // shader.Enable();
        glClearColor(1, 1, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        vec4 ka = vec4(1.0, .4, .4, 1.0);
        vec4 kd = vec4(1.0, .4, .4, 1.0);
        vec4 ks = vec4(.6, .6, .6, 1.0);
        vec4 Ia = vec4(.3, .3, .3, 1.0);
        vec4 Id = vec4(.7, .7, .7, 1.0);
        vec4 Is = vec4(1.0, 1.0, 1.0, 1.0);
        float specular = 50;
        vec4 light = vec4(-1, -1, -1, 0);

        mat4 model(1);
        mat4 v = camera.View();
        mat4 p = camera.Proj();
        mat4 MV = v * model;
        mat4 normM = transpose(inverse(MV));
        glUniformMatrix4fv(shader["modelViewMatrix"], 1, GL_FALSE, value_ptr(MV));
        glUniformMatrix4fv(shader["normalMatrix"], 1,  GL_FALSE, value_ptr(normM));
        glUniformMatrix4fv(shader["projectionMatrix"], 1,  GL_FALSE, value_ptr(p));
        glUniform4fv(shader["ka"], 1, value_ptr(ka));
        glUniform4fv(shader["kd"], 1, value_ptr(kd));
        glUniform4fv(shader["ks"], 1, value_ptr(ks));
        glUniform4fv(shader["Ia"], 1, value_ptr(Ia));
        glUniform4fv(shader["Id"], 1, value_ptr(Id));
        glUniform4fv(shader["Is"], 1, value_ptr(Is));
        glUniform1f(shader["specular"], specular);
        glUniform4fv(shader["lightInEyeSpace"], 1, value_ptr(v * light));

        // glDrawArrays(GL_TRIANGLES, 0, 6);
        glDrawElements(GL_TRIANGLES, mesh.numTriangles*3, GL_UNSIGNED_INT, 0);

        fpsC.EndFrame();

        SDL_GL_SwapWindow(window);
    }

    // Clean up
    SDL_Quit();

    return 0;
}
