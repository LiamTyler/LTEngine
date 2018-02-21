#ifndef INCLUDE_UTILS_H_
#define INCLUDE_UTILS_H_

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <assert.h>
#include <iostream>
#include "glm/glm.hpp"
#include "glm/ext.hpp"

inline std::ostream& operator <<(std::ostream& out, const glm::vec3& v) {
    out << v.x << " " << v.y << " " << v.z;
    return out;
}

inline std::ostream& operator <<(std::ostream& out, const glm::vec4& v) {
    out << v.x << " " << v.y << " " << v.z << " " << v.w;
    return out;
}

SDL_Window* InitAndWindow(const std::string& title, int ox, int oy, int w, int h);

#endif  // INCLUDE_UTILS_H_
