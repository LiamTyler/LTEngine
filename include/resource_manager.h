#ifndef SRC_INCLUDE_RESOURCE_MANAGER_H_
#define SRC_INCLUDE_RESOURCE_MANAGER_H_

#include <vector>
#include "include/mesh.h"

class ResourceManager {
    public:
        ResourceManager();
        // LoadMesh(const std::string& filename, const std::string& meshName);

    private:
        std::vector<Mesh*> meshes_;

};

#endif  // SRC_INCLUDE_RESOURCE_MANAGER_H_
