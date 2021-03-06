#ifndef INCLUDE_RENDER_COMPONENT_H_
#define INCLUDE_RENDER_COMPONENT_H_

#include "include/component.h"
#include "include/material.h"
#include "include/glsl_shader.h"
#include "include/camera.h"

class RenderComponent : public Component {
    public:
        RenderComponent();
        RenderComponent(Material* mat, const std::string& shaderID);
        virtual ~RenderComponent() {}
        virtual void Start() = 0;
        virtual void Update(float dt) = 0;
        virtual void Stop() = 0;
        virtual void Render(Shader& shader, const Camera& camera) = 0;

    protected:
        Material* material_;
        std::string shaderID_;
};

#endif  // INCLUDE_RENDER_COMPONENT_H_
