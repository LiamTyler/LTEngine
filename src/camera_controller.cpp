#include "include/camera_controller.h"
#include "include/input.h"
#include "include/game_object.h"
#include "include/camera.h"

extern Input* input;

CameraController::CameraController() : CameraController(1, .005) {}

CameraController::CameraController(float sLinear, float sAngular) {
    linearSpeed = sLinear;
    angularSpeed = sAngular;
    velocity = glm::vec3(0);
}

void CameraController::Start() {
    camera = (Camera*) gameObject;
}

void CameraController::Update(float dt) {
    if (input->KeyPressed(K_W))
        velocity.z = 1.0f;
    if (input->KeyPressed(K_S))
        velocity.z = -1.0f;
    if (input->KeyPressed(K_A))
        velocity.x = -1.0f;
    if (input->KeyPressed(K_D))
        velocity.x = 1.0f;
    if (input->KeyReleased(K_W))
        velocity.z = 0;
    if (input->KeyReleased(K_S))
        velocity.z = 0;
    if (input->KeyReleased(K_A))
        velocity.x = 0;
    if (input->KeyReleased(K_D))
        velocity.x = 0;

    if (input->MouseMotionEvent()) {
        glm::vec3 rot(-input->mouse.dy, -input->mouse.dx, 0);
        gameObject->transform.rotation += angularSpeed * rot;
    }
    camera->UpdateOrientationVectors();
    const glm::vec3& dir = camera->GetForwardDir();
    const glm::vec3& up = camera->GetUpDir();
    const glm::vec3& right = camera->GetRightDir();
    camera->transform.position += dt * linearSpeed * (
            velocity.x * right +
            velocity.y * up +
            velocity.z * dir);
    camera->UpdateViewMatrix();
}

void CameraController::Stop() {
}
