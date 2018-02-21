#ifndef INCLUDE_RENDER_COMPONENT_H_
#define INCLUDE_RENDER_COMPONENT_H_

#include "include/component.h"
#include "include/material.h"
#include "include/glsl_shader.h"

class RenderComponent : public Component {
    public:
        RenderComponent();
        RenderComponent(Material* mat, const std::string& shaderID);
        virtual ~RenderComponent() {}
        virtual void Start() = 0;
        virtual void Update() = 0;
        virtual void Stop() = 0;
        virtual void Render(Shader& shader, glm::mat4& V) = 0;

    protected:
        Material* material_;
        std::string shaderID_;
};

#endif  // INCLUDE_RENDER_COMPONENT_H_
