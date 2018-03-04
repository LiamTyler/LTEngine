#ifndef INCLUDE_MATERIAL_H_
#define INCLUDE_MATERIAL_H_

#include <iostream>
#include "include/utils.h"
#include "include/resource.h"
#include "include/texture.h"

class Material : public Resource {
    public:
        Material();
        ~Material();
        Material(glm::vec4 a, glm::vec4 d, glm::vec4 s, float spec, Texture* tex = nullptr);
        friend std::ostream& operator<<(std::ostream& out, const Material& m);
        
        glm::vec4 ka;
        glm::vec4 kd;
        glm::vec4 ks;
        float specular;
        Texture* diffuseTex;
};

#endif  // INCLUDE_MATERIAL_H_
