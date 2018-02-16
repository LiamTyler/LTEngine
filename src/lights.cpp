#include "include/lights.h"

Light::Light() : Light(
        vec3(0, 0, 0),
        vec3(0, 0, 0),
        vec3(0, 0, 0),
        vec3(0, 0, 0)) {

}

Light::Light(vec3 d, vec3 ka, vec3 kd, vec3 ks) {
    dir_ = vec4(d, 0);
    mat_ = Material(ka, kd, ks, 0);
}
