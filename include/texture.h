#ifndef INCLUDE_TEXTURE_H_
#define INCLUDE_TEXTURE_H_

#include "include/utils.h"
#include "include/resource.h"

class Texture : public Resource {
    public:
        Texture();
        Texture(const std::string& fname);
        Texture(const std::string& fname, bool mip_mapped);

        GLuint GetHandle();

    protected:
        GLuint LoadTexture(const std::string& fname, bool mip_mapped);
        GLuint tex_handle_;
};
#endif  // INCLUDE_TEXTURE_H_
