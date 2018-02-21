#include "include/mesh.h"

Mesh::Mesh() : Mesh(
        0,
        0,
        nullptr,
        nullptr,
        nullptr)
{
}

Mesh::Mesh(unsigned int numV, unsigned int numT, glm::vec3* verts,
        glm::vec3* norms, glm::ivec3* indices) : Resource(-1) {
    numVertices_ = numV;
    numTriangles_ = numT;
    vertices_ = verts;
    normals_ = norms;
    indices_ = indices;
}

Mesh::~Mesh() {
    if (vertices_)
        delete [] vertices_;
    if (normals_)
        delete [] normals_;
    if (indices_)
        delete [] indices_;
}

std::ostream& operator<<(std::ostream& out, const Mesh& m) {
    out << "Mesh: " << m.rid << std::endl;
    out << "\tNumVertices: " << m.numVertices_ << std::endl;
    out << "\tNumTriangles: " << m.numTriangles_ << std::endl;
    out << "\tVertices: " << m.vertices_ << std::endl;
    out << "\tNormals: " << m.normals_ << std::endl;
    out << "\tIndices: " << m.indices_ << std::endl;
}
