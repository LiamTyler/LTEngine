#ifndef SRC_INCLUDE_MESH_H_
#define SRC_INCLUDE_MESH_H_

#include "include/OBJ_Loader.h"
#include "glm/glm.hpp"

class Mesh {
    public:
        Mesh();
        Mesh(const std::string& filename, const std::string& mName);
        ~Mesh();

        void LoadMesh(const std::string& filename);

        bool loaded;
        std::string name;
        unsigned int numVertices;
        unsigned int numTriangles;
        glm::vec3 * vertices;
        glm::vec3 * normals;
        glm::ivec3 * indices;
};

#endif  // SRC_INCLUDE_MESH_H_
