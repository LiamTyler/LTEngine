#ifndef INCLUDE_MATERIAL_H_
#define INCLUDE_MATERIAL_H_

#include "include/utils.h"

class Material {
    public:
        Material();
        Material(vec3 a, vec3 d, vec3 s, float spec);

        glm::vec4 ka;
        glm::vec4 kd;
        glm::vec4 ks;
        float specular;
};

#endif  // INCLUDE_MATERIAL_H_
