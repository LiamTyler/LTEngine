#include "include/material.h"

Material::Material() : Material(
        glm::vec3(0, 0, 0),
        glm::vec3(0, 0, 0),
        glm::vec3(0, 0, 0),
        0) {

}

Material::Material(glm::vec3 a, glm::vec3 d, glm::vec3 s, float spec) {
    ka = glm::vec4(a, 1);
    kd = glm::vec4(d, 1);
    ks = glm::vec4(s, 1);
    specular = spec;
}
