#ifndef INCLUDE_MESH_H_
#define INCLUDE_MESH_H_

#include "include/utils.h"
#include "include/resource.h"

class Mesh : public Resource {
    public:
        Mesh();
        Mesh(unsigned int numV, unsigned int numT, glm::vec3* verts,
                glm::vec3* norms, glm::ivec3* indices);
        ~Mesh();

        Mesh& operator=(const Mesh& m);
        Mesh(const Mesh& m);

        friend std::ostream& operator<<(std::ostream& out, const Mesh& m);

        unsigned int GetNumVertices() const { return numVertices; }
        unsigned int GetNumTriangles() const { return numTriangles; }
        glm::vec3* GetVertices() const { return vertices; }
        glm::vec3* GetNormals() const { return normals; }
        glm::ivec3* GetIndices() const { return indices; }

        unsigned int numVertices;
        unsigned int numTriangles;
        glm::vec3* vertices;
        glm::vec3* normals;
        glm::ivec3* indices;
};

#endif  // INCLUDE_MESH_H_
