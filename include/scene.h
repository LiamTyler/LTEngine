#ifndef INCLUDE_SCENE_H_
#define INCLUDE_SCENE_H_

#include <vector>
#include "include/game_object.h"
#include "include/camera.h"
#include "include/lights.h"

class Scene {
    public:
        Scene();
        ~Scene();
        void AddObject(GameObject* o);

        std::vector<GameObject*> GameObjects() const { return gameObjects_; }
        Camera* GetCamera() { return camera_; }
        void SetCamera(Camera* c) { camera_ = c; }
        Light& GetLight() { return light_; }
        void SetLight(Light l) { light_ = l; }

    protected:
        std::vector<GameObject*> gameObjects_;
        Camera* camera_;
        Light light_;
};

#endif  // INCLUDE_SCENE_H_
