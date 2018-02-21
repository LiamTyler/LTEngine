#include "include/render_component.h"

RenderComponent::RenderComponent() : RenderComponent(nullptr, "") {}

RenderComponent::RenderComponent(Material* mat,
        const std::string& shaderID) {
    material_ = mat;
    shaderID_ = shaderID;
}
