#ifndef INCLUDE_CAMERA_CONTROLLER_H_
#define INCLUDE_CAMERA_CONTROLLER_H_

#include "include/component.h"

class Camera;

class CameraController : public Component {
    public:
        CameraController();
        CameraController(float sLinear, float sAngular);
        void Start();
        void Update(float dt);
        void Stop();

        Camera* camera;
        glm::vec3 velocity;
        float linearSpeed;
        float angularSpeed;
};

#endif  // INCLUDE_CAMERA_CONTROLLER_H_
