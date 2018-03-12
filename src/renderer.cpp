#include "include/renderer.h"

Renderer::Renderer() {
    shader_ = nullptr;
}

Renderer::~Renderer() {
    if (shader_)
        delete shader_;
}

void Renderer::RenderScene(const Scene& scene) {
    // clear screen
    glm::vec4& c = scene.background->color;
    glClearColor(c.r, c.g, c.b, c.a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
