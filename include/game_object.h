#ifndef INCLUDE_GAME_OBJECT_H_
#define INCLUDE_GAME_OBJECT_H_

#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include "include/transform.h"
#include "include/component.h"

class GameObject {
    public:
        GameObject();
        GameObject(Transform t);
        ~GameObject();

        void Update(float dt);
        template<typename ComponentType>
        void AddComponent(Component* c);
        template<typename ComponentType>
        void RemoveComponent();
        template<typename ComponentType>
        ComponentType* GetComponent();
        
        Transform transform;

    protected:
        std::unordered_map<std::type_index, Component*> component_list_;
};

template<typename ComponentType>
ComponentType* GameObject::GetComponent() {
    assert(component_list_.find(typeid(ComponentType)) != component_list_.end());
    return (ComponentType*) component_list_[typeid(ComponentType)];
}

template<typename ComponentType>
void GameObject::AddComponent(Component* c) {
    assert(component_list_.find(typeid(ComponentType)) == component_list_.end());
    c->gameObject = this;
    c->Start();
    component_list_[typeid(ComponentType)] = c;
}

template<typename ComponentType>
void GameObject::RemoveComponent() {
    assert(component_list_.find(typeid(ComponentType)) != component_list_.end());
    Component* c = component_list_[typeid(ComponentType)];
    c->Stop();
    delete c;
    component_list_.erase(typeid(ComponentType));
}

#endif  // INCLUDE_GAME_OBJECT_H_
