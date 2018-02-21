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
        friend std::ostream& operator<<(std::ostream& out, const Mesh& m);

        unsigned int GetNumVertices() const { return numVertices_; }
        unsigned int GetNumTriangles() const { return numTriangles_; }
        glm::vec3* GetVertices() const { return vertices_; }
        glm::vec3* GetNormals() const { return normals_; }
        glm::ivec3* GetIndices() const { return indices_; }

    private:
        unsigned int numVertices_;
        unsigned int numTriangles_;
        glm::vec3* vertices_;
        glm::vec3* normals_;
        glm::ivec3* indices_;
};

#endif  // INCLUDE_MESH_H_
