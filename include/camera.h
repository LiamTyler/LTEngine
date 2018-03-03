#ifndef INCLUDE_CAMERA_H_
#define INCLUDE_CAMERA_H_

#include "include/utils.h"
#include "include/game_object.h"

class Camera : public GameObject {
    public:
        Camera();
        Camera(const glm::vec3& pos);
        Camera(Transform t);
        Camera(Transform t, float fov, float a, float np, float fp);

        glm::mat4 GetV();
        glm::mat4 GetP();
        float GetFOV();
        float GetAspectRatio();
        float GetNearPlane();
        float GetFarPlane();
        void SetFOV(float f);
        void SetAspectRatio(float a);
        void SetNearPlane(float p);
        void SetFarPlane(float p);
        void UpdateOrientationVectors();
        void UpdateViewMatrix();
        glm::vec3 GetForwardDir();
        glm::vec3 GetUpDir();
        glm::vec3 GetRightDir();

    protected:
        void UpdateProjectionMatrix();
        float FOV;
        float aspectRatio;
        float nearPlane;
        float farPlane;
        glm::mat4 viewMatrix;
        glm::mat4 projectionMatrix;
        glm::vec3 currDir;
        glm::vec3 currUp;
        glm::vec3 currRight;
};

#endif  // INCLUDE_CAMERA_H_
