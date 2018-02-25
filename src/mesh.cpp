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
    numVertices = numV;
    numTriangles = numT;
    vertices = verts;
    normals = norms;
    indices = indices;
}

Mesh::~Mesh() {
    if (vertices)
        delete [] vertices;
    if (normals)
        delete [] normals;
    if (indices)
        delete [] indices;
}

Mesh::Mesh(const Mesh& m) {
    *this = m;
}

Mesh& Mesh::operator=(const Mesh& m) {
    numVertices = m.numVertices;
    numTriangles = m.numTriangles;
    vertices = new glm::vec3[numVertices];
    normals = new glm::vec3[numVertices];
    indices = new glm::ivec3[numTriangles];
    memcpy(vertices, m.vertices, sizeof(glm::vec3) * numVertices);
    memcpy(normals, m.normals, sizeof(glm::vec3) * numVertices);
    memcpy(indices, m.indices, sizeof(glm::ivec3) * numTriangles);
}

std::ostream& operator<<(std::ostream& out, const Mesh& m) {
    out << "Mesh: " << m.rid << std::endl;
    out << "\tNumVertices: " << m.numVertices << std::endl;
    out << "\tNumTriangles: " << m.numTriangles << std::endl;
    out << "\tVertices: " << m.vertices << std::endl;
    out << "\tNormals: " << m.normals << std::endl;
    out << "\tIndices: " << m.indices << std::endl;
}
