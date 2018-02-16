#include "include/scene.h"

Scene::Scene() {

}

Scene::~Scene() {
    for (int i = 0; i < gameObjects_.size(); i++) {
        delete gameObjects_[i];
    }
}

void Scene::AddObject(GameObject* o) {
    gameObjects_.push_back(o);
}
