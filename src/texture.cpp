#include "include/texture.h"
#include "include/image.h"

Texture::Texture() : Texture("") {}

Texture::Texture(const std::string& fname) : Texture(fname, false) {}

Texture::Texture(const std::string& fname, bool mip_mapped) : Resource(-1) {
    tex_handle_ = LoadTexture(fname, mip_mapped);
}

GLuint Texture::GetHandle() { return tex_handle_; }

GLuint Texture::LoadTexture(const std::string& fname, bool mip_mapped) {
    Image image;
    if (!image.LoadImage(fname)) {
        std::cerr << "Failed to load tex: " << fname << std::endl;
        return -1;
    }

    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.Width(), image.Height(), 0, GL_RGBA,
            GL_FLOAT, image.Data());
    if (mip_mapped) {
        glGenerateMipmap(GL_TEXTURE_2D);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                GL_LINEAR_MIPMAP_LINEAR);
    } else {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    }
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    return tex;
}
