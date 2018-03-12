#pragma once

#include "include/utils.h"
#include "include/lights.h"
#include "include/camera.h"
#include "include/game_object.h"
#include "include/background.h"

class Scene {
    public:
        Scene();
        ~Scene();
    
        void SetCamera(Camera* c);
        void SetBackground(Background* bg);
        void AddGameObject(GameObject* gameObj);
        void AddLight(Light* light);

        Camera* camera;
        std::vector<Light*> lights;
        std::vector<GameObject*> gameObjects;
        Background* background;
};
