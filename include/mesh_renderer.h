#ifndef INCLUDE_MESH_RENDERER_H_
#define INCLUDE_MESH_RENDERER_H_

#include "include/render_component.h"
#include "include/mesh.h"

class MeshRenderer : public RenderComponent {
    public:
        MeshRenderer();
        MeshRenderer(Mesh* mesh, Material* mat, const std::string& shaderID);
        ~MeshRenderer();

        void Start();
        void Update(float dt);
        void Stop();
        void Render(Shader& shader, glm::mat4& V);

    protected:
        Mesh* mesh_;
};

#endif  // INCLUDE_MESH_RENDERER_H_
