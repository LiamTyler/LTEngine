#ifndef INCLUDE_COMPONENT_H_
#define INCLUDE_COMPONENT_H_

#include "include/utils.h"

class GameObject;

class Component {
    public:
        Component() : Component(nullptr) {}
        Component(GameObject* obj) : gameObject(obj) {}
        virtual ~Component() {}
        virtual void Start() = 0;
        virtual void Update() = 0;
        virtual void Stop() = 0;

        GameObject* gameObject;
};

#endif  // INCLUDE_COMPONENT_H_
