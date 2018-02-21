#include "include/material.h"
#include "include/resource_manager.h"

Material::Material() : Material(
        glm::vec4(0, 0, 0, 1),
        glm::vec4(0, 0, 0, 1),
        glm::vec4(0, 0, 0, 1),
        0)
{
}

Material::~Material() {
    std::cout << "in material destructor" << std::endl;
}

Material::Material(glm::vec4 a, glm::vec4 d, glm::vec4 s, float spec) : Resource(-1) {
    ka = a;
    kd = d;
    ks = s;
    specular = spec;
}

std::ostream& operator<<(std::ostream& out, const Material& m) {
    out << "Material: " << m.rid << std::endl;
    out << "\tka: " << m.ka << std::endl;
    out << "\tkd: " << m.kd << std::endl;
    out << "\tks: " << m.ks << std::endl;
    out << "\tspecular: " << m.specular << std::endl;

    return out;
}
