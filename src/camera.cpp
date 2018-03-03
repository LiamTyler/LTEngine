#include "include/camera.h"

Camera::Camera() : Camera(Transform()) {
}

Camera::Camera(const glm::vec3& pos) : Camera(Transform(pos)) {
}

Camera::Camera(Transform t) :
    Camera(t, glm::radians(45.0f), 4.0f/3.0f, .1f, 100.0f ) {
}

Camera::Camera(Transform t, float fov, float a, float np, float fp) : GameObject(t) {
    transform = t;
    FOV = fov;
    aspectRatio = a;
    nearPlane = np;
    farPlane = fp;
    UpdateProjectionMatrix();
    UpdateViewMatrix();
}

void Camera::UpdateOrientationVectors() {
    glm::mat4 rot(1);
    rot = glm::rotate(rot, transform.rotation.y, glm::vec3(0, 1, 0));
    rot = glm::rotate(rot, transform.rotation.x, glm::vec3(1, 0, 0));
    currDir = glm::vec3(rot * glm::vec4(0, 0, -1, 0));
    currUp = glm::vec3(rot * glm::vec4(0, 1, 0, 0));
    currRight = glm::cross(currDir, currUp);
}

void Camera::UpdateViewMatrix() {
    viewMatrix = glm::lookAt(
            transform.position,
            transform.position + currDir,
            currUp);
}

void Camera::UpdateProjectionMatrix() {
    projectionMatrix = glm::perspective(FOV, aspectRatio, nearPlane, farPlane);
}

glm::mat4 Camera::GetV() { return viewMatrix; }
glm::mat4 Camera::GetP() { return projectionMatrix; }
float Camera::GetFOV() { return FOV; }
float Camera::GetAspectRatio() { return aspectRatio; }
float Camera::GetNearPlane() { return nearPlane; }
float Camera::GetFarPlane() { return farPlane; }
glm::vec3 Camera::GetForwardDir() { return currDir; }
glm::vec3 Camera::GetUpDir() { return currUp; }
glm::vec3 Camera::GetRightDir() { return currRight; }

void Camera::SetFOV(float f) {
    FOV = f;
    UpdateProjectionMatrix();
}

void Camera::SetAspectRatio(float a) {
    aspectRatio = a;
    UpdateProjectionMatrix();
}

void Camera::SetNearPlane(float p) {
    nearPlane = p;
    UpdateProjectionMatrix();
}

void Camera::SetFarPlane(float p) {
    farPlane = p;
    UpdateProjectionMatrix();
}
