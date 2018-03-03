#include "include/game_object.h"

GameObject::GameObject() : GameObject(
        Transform())
{
}

GameObject::GameObject(Transform t) {
    transform = t;
    component_list_.clear();
}

GameObject::~GameObject() {
    for (auto& c : component_list_) {
        c.second->Stop();
        delete c.second;
    }
}

void GameObject::Update(float dt) {
    for (auto& c : component_list_)
        c.second->Update(dt);
}
