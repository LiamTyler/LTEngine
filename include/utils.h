#ifndef INCLUDE_UTILS_H_
#define INCLUDE_UTILS_H_

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include "glm/glm.hpp"
#include "glm/ext.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace glm;
using namespace std;

inline ostream& operator <<(ostream& out, const vec3& v) {
    out << v.x << " " << v.y << " " << v.z;
    return out;
}

inline ostream& operator <<(ostream& out, const vec4& v) {
    out << v.x << " " << v.y << " " << v.z << " " << v.w;
    return out;
}

GLuint LoadTexture(string path);

SDL_Window* InitAndWindow(string title, int ox, int oy, int w, int h);

#endif  // INCLUDE_UTILS_H_
