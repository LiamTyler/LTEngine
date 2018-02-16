#ifndef INCLUDE_GAME_OBJECT_H_
#define INCLUDE_GAME_OBJECT_H_

#include "include/utils.h"
#include "include/mesh.h"
#include "include/material.h"

class GameObject {
    public:
        GameObject();

        glm::mat4 ModelMatrix();

        Mesh* GetMesh() { return mesh_; }
        void SetMesh(Mesh* m) { mesh_ = m; }

    protected:
        vec3 pos_;
        vec3 rotation_;
        vec3 scale_;
        Mesh* mesh_;
};

#endif  // INCLUDE_GAME_OBJECT_H_
