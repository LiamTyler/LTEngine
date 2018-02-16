#include "include/game_object.h"

GameObject::GameObject() {
    pos_ = vec3(0, 0, 0);
    rotation_ = vec3(0, 0, 0);
    scale_ = vec3(1, 1, 1);
}

glm::mat4 GameObject::ModelMatrix() {
    mat4 model(1);
    model = translate(model, pos_);
    model = rotate(model, rotation_.z, vec3(0, 0, 1));
    model = rotate(model, rotation_.y, vec3(0, 1, 0));
    model = rotate(model, rotation_.x, vec3(1, 0, 0));
    model = scale(model, scale_);

    return model;
}
