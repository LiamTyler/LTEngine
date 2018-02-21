#ifndef INCLUDE_RENDERER_H_
#define INCLUDE_RENDERER_H_

#include <unordered_map>
#include "include/utils.h"
#include "include/glsl_shader.h"
#include "include/game_object.h"
#include "include/camera.h"
#include "include/render_component.h"

class VaoGroup {
    public:
        VaoGroup() {}

        unsigned int vao_index;
        std::vector<RenderComponent*> objects_;
};

class ShaderGroup {
    public:
        ShaderGroup() {}

        unsigned int shader_index;
        std::vector<VaoGroup> vaoGroups_;
};

class Renderer {
    public:
        Renderer();
        ~Renderer();        

        Shader* GetShader(const std::string& id);
        Shader* AddShader(const std::string& id, const std::string& vShader,
                const std::string& fShader, const std::string& cShader);
        bool VaoExists(RID r);
        GLuint CreateAndRegisterVao(const std::string& shaderID, RID r, RenderComponent* rc);
        GLuint* CreateVbos(int num);
        void RenderScene(Camera& camera);

        struct Map {
            unsigned int shaderGroup;
            unsigned int vaoGroup;
        };

    protected:
        // the order of appearance is the same in shaders_, shaderGroups_,
        // and shader_mapping_
        std::vector<ShaderGroup> shaderGroups_;
        std::vector<Shader*> shaders_;
        std::vector<GLuint> vaos_;
        std::vector<GLuint> vbos_;
        std::unordered_map<std::string, unsigned int> shader_mapping_;
        std::unordered_map<RID, struct Map> vao_mapping_;
};

#endif  // INCLUDE_RENDERER_H_
