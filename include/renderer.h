#ifndef INCLUDE_RENDERER_H_
#define INCLUDE_RENDERER_H_

#include "include/utils.h"
#include "include/shader.h"
#include "include/scene.h"

class Renderer {
    public:
        Renderer();
        ~Renderer();

        void RenderScene(const Scene& scene);

    protected:
        Shader* shader_;
};

#endif  // INCLUDE_RENDERER_H_
