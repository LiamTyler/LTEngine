#include "include/game_object.h"

GameObject::GameObject() : GameObject(
        Transform(),
        nullptr)
{
}

GameObject::GameObject(Transform t, RenderComponent* r) {
    transform = t;
    renderComponent = r;
    renderComponent->gameObject = this;
    renderComponent->Start();
}

GameObject::~GameObject() {
    if (renderComponent)
        delete renderComponent;
}

void GameObject::Update() {
    if (renderComponent)
        renderComponent->Update();
}
