#include <iostream>
#include "include/mesh.h"
#include "include/OBJ_Loader.h"

Mesh::Mesh() {
    modelID_ = 0;
    loaded_ = false;
    numVertices_ = 0;
    numTriangles_ = 0;
    vertices_= nullptr;
    normals_ = nullptr;
    indices_ = nullptr;
}

Mesh::Mesh(const std::string& filename, unsigned int id) {
    modelID_ = id;
    loaded_ = false;
    numVertices_ = 0;
    numTriangles_ = 0;
    vertices_ = nullptr;
    normals_ = nullptr;
    indices_ = nullptr;

    LoadMesh(filename);
}

Mesh::~Mesh() {
    if (vertices_)
        delete vertices_;
    if (normals_)
        delete normals_;
    if (indices_)
        delete indices_;
}

void Mesh::LoadMesh(const std::string& fname) {
    loaded_ = false;
    objl::Loader Loader;
    bool loaded = Loader.LoadFile(fname);
    if (!loaded) {
        std::cout << "Failed to open/load file: " << fname << std::endl;
        return;
    }
    objl::Mesh m = Loader.LoadedMeshes[0];
    numVertices_ = m.Vertices.size();
    vertices_ = new glm::vec3[numVertices_];
    normals_  = new glm::vec3[numVertices_];
    for (int i = 0; i < numVertices_; i++) {
        float x,y,z;
        x = m.Vertices[i].Position.X;
        y = m.Vertices[i].Position.Y;
        z = m.Vertices[i].Position.Z;
        vertices_[i] = glm::vec3(x, y, z);
        x = m.Vertices[i].Normal.X;
        y = m.Vertices[i].Normal.Y;
        z = m.Vertices[i].Normal.Z;
        normals_[i] = glm::vec3(x, y, z);
    }
    numTriangles_ = m.Indices.size() / 3;
    indices_ = new glm::ivec3[numTriangles_];
    int tri = 0;
    for (int i = 0; i < m.Indices.size();) {
        unsigned int x = m.Indices[i++];
        unsigned int y = m.Indices[i++];
        unsigned int z = m.Indices[i++];
        indices_[tri++] = glm::ivec3(x, y, z);
    }
    loaded_ = true;
}
