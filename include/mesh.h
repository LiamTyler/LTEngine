#ifndef INCLUDE_MESH_H_
#define INCLUDE_MESH_H_

#include "include/utils.h"
#include "include/material.h"

class Mesh {
    public:
        Mesh();
        Mesh(const std::string& filename, unsigned int id);
        ~Mesh();

        void LoadMesh(const std::string& filename);

        void SetMaterial(Material m) { mat_ = m; }
        Material GetMaterial() { return mat_; }
        bool IsLoaded() { return loaded_; }
        unsigned int ModelID() { return modelID_; }
        unsigned int NumVertices() { return numVertices_; }
        unsigned int NumTriangles() { return numTriangles_; }
        glm::vec3* Vertices() { return vertices_; }
        glm::vec3* Normals() { return normals_; }
        glm::ivec3* Indices() { return indices_; }


    protected:
        Material mat_;
        bool loaded_;
        unsigned int modelID_;
        unsigned int numVertices_;
        unsigned int numTriangles_;
        glm::vec3* vertices_;
        glm::vec3* normals_;
        glm::ivec3* indices_;
};

#endif  // INCLUDE_MESH_H_
