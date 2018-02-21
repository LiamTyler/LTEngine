#include "include/camera.h"

Camera::Camera() : Camera(
        glm::vec3(0, 0, 0),
        glm::vec3(0, 0, -1),
        glm::vec3(0, 1, 0)) {}

Camera::Camera(glm::vec3 pos, glm::vec3 dir, glm::vec3 up) : Camera(pos, dir, up, 1, 0.005) {}

Camera::Camera(glm::vec3 pos, glm::vec3 dir, glm::vec3 up, float sLinear, float sAngular) {
    pos_ = pos;
    initialDir_ = dir;
    initialUp_ = up;
    initialRight_ = cross(initialDir_, initialUp_);
    currDir_ = initialDir_;
    currUp_ = initialUp_;
    currRight_ = initialRight_;
    speedLinear_ = sLinear;
    speedAngular_ = sAngular;
    Setup();
}

void Camera::Setup() {
    SetProjection(glm::radians(45.0f), 4.0f/3.0f, 0.1f, 100.0f);
}

void Camera::SetProjection(float fov, float aspect, float near_p, float far_p) {
    projection_ = glm::perspective(fov, aspect, near_p, far_p);
}

void Camera::UpdateViewMatrix() {
    view_ = glm::lookAt(pos_, pos_ + currDir_, currUp_);
}

void Camera::Update(float dt) {
    pos_ = pos_ + dt * speedLinear_ * (vel_.z*currDir_ + vel_.x*currRight_);
    UpdateViewMatrix();
}

void Camera::UpdateAxis() {
    glm::mat4 rot(1);
    rot = glm::rotate(rot, rotation_.y, initialUp_);
    rot = glm::rotate(rot, rotation_.x, initialRight_);
    currDir_ = glm::vec3(rot*glm::vec4(initialDir_, 0));
    currUp_ = glm::vec3(rot*glm::vec4(initialUp_, 0));
    currRight_ = glm::cross(currDir_, currUp_);
}

void Camera::RotateY(float y) {
    rotation_.y += y*speedAngular_;
}

void Camera::RotateX(float x) {
    float cap = glm::radians(85.0f);
    rotation_.x = fmin(cap, fmax(-cap, rotation_.x + x * speedAngular_));
}
