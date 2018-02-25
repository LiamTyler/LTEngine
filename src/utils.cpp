#include "include/utils.h"
// #include "include/image.h"

/*
GLuint LoadTexture(string path) {
    Image image;
    if (!image.LoadImage(path)) {
        std::cerr << "Failed to load tex: " << path << std::endl;
        return -1;
    }

    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.Width(), image.Height(), 0, GL_RGBA,
            GL_FLOAT, image.Data());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    return tex;
}
*/
