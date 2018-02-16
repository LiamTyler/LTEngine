#ifndef INCLUDE_LIGHTS_H_
#define INCLUDE_LIGHTS_H_

#include "include/utils.h"
#include "include/material.h"

class Light {
    public:
        Light();
        Light(vec3 d, vec3 ka, vec3 kd, vec3 ks);

        vec4 Dir() { return dir_; }
        Material GetMaterial() { return mat_; }

    protected:
        vec4 dir_;
        Material mat_;
};

#endif  // INCLUDE_LIGHTS_H_
