#ifndef INCLUDE_RENDERER_H_
#define INCLUDE_RENDERER_H_

#include <vector>
#include "include/glsl_shader.h"
#include "include/scene.h"
#include "include/game_object.h"

class Renderer {
    public:
        Renderer();
        ~Renderer();
        void Init();
        void LoadScene(Scene* scene);
        void RenderScene(Scene* scene);
        GLSLShader* GetShader() { return shader_; }
        std::vector<GLuint> GetVAOS() { return vaos_; }
        std::vector<GLuint> GetVBOS() { return vbos_; }

    protected:
        void RenderGameObject(GameObject* obj, glm::mat4& V);

        GLSLShader* shader_;
        std::vector<GLuint> vaos_;
        std::vector<GLuint> vbos_;
};

#endif  // INCLUDE_RENDERER_H_
