#ifndef INCLUDE_GAME_OBJECT_H_
#define INCLUDE_GAME_OBJECT_H_

#include "include/transform.h"
#include "include/render_component.h"

class GameObject {
    public:
        GameObject();
        GameObject(Transform t, RenderComponent* r);
        ~GameObject();

        void Update();
        
        Transform transform;
        RenderComponent* renderComponent;
};

#endif  // INCLUDE_GAME_OBJECT_H_
