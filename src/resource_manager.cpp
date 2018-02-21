#include "include/resource_manager.h"
#include "include/OBJ_Loader.h"

ResourceManager::ResourceManager() {
    count_ = 0;
}

ResourceManager::~ResourceManager() {
    for (auto it = resource_map_.begin(); it != resource_map_.end(); ++it) {
        delete it->second.resource;
    }
}

void ResourceManager::ReleaseResource(RID id) {
    resource_map_[id].count -= 1;
    if (resource_map_[id].count == 0)
        DestoryResource(id);
}

void ResourceManager::IncreaseResourceCount(RID id) {
    resource_map_[id].count += 1;
}

RID ResourceManager::AllocateRID() {
    return RID(count_++);
}

void ResourceManager::DestoryResource(RID id) {
    delete resource_map_[id].resource;
    resource_map_.erase(id);
}

Mesh* ResourceManager::LoadMesh(const std::string& fname) {
    objl::Loader Loader;
    bool loaded = Loader.LoadFile(fname);
    if (!loaded) {
        std::cout << "Failed to open/load file: " << fname << std::endl;
        return nullptr;
    }
    objl::Mesh m = Loader.LoadedMeshes[0];
    unsigned int numVerts = m.Vertices.size();
    glm::vec3* vertices = new glm::vec3[numVerts];
    glm::vec3* normals  = new glm::vec3[numVerts];
    for (int i = 0; i < numVerts; i++) {
        float x,y,z;
        x = m.Vertices[i].Position.X;
        y = m.Vertices[i].Position.Y;
        z = m.Vertices[i].Position.Z;
        vertices[i] = glm::vec3(x, y, z);
        x = m.Vertices[i].Normal.X;
        y = m.Vertices[i].Normal.Y;
        z = m.Vertices[i].Normal.Z;
        normals[i] = glm::vec3(x, y, z);
    }
    unsigned int numTris = m.Indices.size() / 3;
    glm::ivec3* indices = new glm::ivec3[numTris];
    int tri = 0;
    for (int i = 0; i < m.Indices.size();) {
        unsigned int x = m.Indices[i++];
        unsigned int y = m.Indices[i++];
        unsigned int z = m.Indices[i++];
        indices[tri++] = glm::ivec3(x, y, z);
    }
    Mesh mesh(numVerts, numTris, vertices, normals, indices);
    return AllocateResource<Mesh>(mesh);
}

void ResourceManager::Display() {
    std::cout << "Resouce Manager: " << std::endl;
    for (auto it = resource_map_.begin(); it != resource_map_.end(); ++it) {
        std::cout << "RID: " << it->first << ", Count: " << it->second.count << std::endl;
    }
}
