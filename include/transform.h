#ifndef INCLUDE_TRANSFORM_H_
#define INCLUDE_TRANSFORM_H_

#include "include/utils.h"

class Transform {
    public:
        Transform();
        Transform(const glm::vec3& pos);
        Transform(const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& scale);

        glm::mat4 GetModelMatrix();

        glm::vec3 position;
        glm::vec3 rotation;
        glm::vec3 scale;
};

#endif  // INCLUDE_TRANSFORM_H_
