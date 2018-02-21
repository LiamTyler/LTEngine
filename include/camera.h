#ifndef INCLUDE_CAMERA_H_
#define INCLUDE_CAMERA_H_

#include "include/utils.h"

class Camera {
    public:
        Camera();
        Camera(glm::vec3 pos, glm::vec3 dir, glm::vec3 up);
        Camera(glm::vec3 pos, glm::vec3 dir, glm::vec3 up, float sLinear, float sAngular);
        void Setup();

        void SetProjection(float fov, float aspect, float near_p, float far_p);
        void Update(float dt);
        void UpdateAxis();
        void UpdateViewMatrix();

        void RotateY(float y);
        void RotateX(float x);

        // Getters
        glm::mat4 View() { return view_; }
        glm::mat4 Proj() { return projection_; }
        glm::mat4 VP() { return projection_ * view_; }
        glm::vec3 Vel() { return vel_; }
        glm::vec3 Pos() { return pos_; }
        glm::vec3 Dir() { return currDir_; }
        glm::vec3 Up() { return currUp_; }
        glm::vec3 Right() { return currRight_; }

        // Setters
        void VelX(float x) { vel_.x = x; }
        void VelY(float y) { vel_.y = y; }
        void VelZ(float z) { vel_.z = z; }
        void Vel(glm::vec3 vel) { vel_ = vel; }
        void Pos(glm::vec3 p) { pos_ = p; }

    protected:
        glm::vec3 pos_;
        glm::vec3 initialDir_;
        glm::vec3 initialUp_;
        glm::vec3 initialRight_;
        glm::vec3 currDir_;
        glm::vec3 currUp_;
        glm::vec3 currRight_;
        glm::vec3 vel_;

        float speedAngular_;
        float speedLinear_;
        glm::vec2 rotation_;

        glm::mat4 view_;
        glm::mat4 projection_;
};

#endif  // INCLUDE_CAMERA_H_
