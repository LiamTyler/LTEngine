#ifndef INCLUDE_RESOURCE_MANAGER_H_
#define INCLUDE_RESOURCE_MANAGER_H_

#include <unordered_map>
#include "include/utils.h"
#include "include/resource.h"
#include "include/mesh.h"

class ResourceManager {
    public:
        ResourceManager();
        ~ResourceManager();

        template<class T>
        T* AllocateResource();
        template<class T>
        T* AllocateResource(T& resource);
        template<class T>
        T* GetResource(RID id);

        Mesh* LoadMesh(const std::string& fname);

        void ReleaseResource(RID id);
        void IncreaseResourceCount(RID id);

        void Display();

    private:
        RID AllocateRID();
        void DestoryResource(RID id);

        typedef struct ResourceCount {
            ResourceCount() {
                count = -1; resource = nullptr;
            }
            ResourceCount(unsigned int c, Resource* r) {
                count = c; resource = r;
            }
            unsigned int count;
            Resource* resource;
        } ResourceCount;

        std::unordered_map<RID, ResourceCount> resource_map_;
        unsigned int count_;
};

template<class T>
T* ResourceManager::AllocateResource() {
    T* resource = new T;
    RID newID = AllocateRID();
    ResourceCount rc(1, resource);
    resource_map_[newID] = rc;
    resource->rid = newID;
    return resource;
}

template<class T>
T* ResourceManager::AllocateResource(T& resource) {
    T* newResource = new T;
    RID newID = AllocateRID();
    ResourceCount rc(1, newResource);
    resource_map_[newID] = rc;
    *newResource = resource;
    newResource->rid = newID;
    return newResource;
}

template<class T>
T* ResourceManager::GetResource(RID id) {
    std::unordered_map<RID, ResourceCount>::iterator it = resource_map_.find(id);
    if (it != resource_map_.end())
        return (T* ) it->second.resource;
    else
        return nullptr;
}

#endif  // INCLUDE_RESOURCE_MANAGER_H_
