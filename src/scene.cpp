#include "include/scene.h"

Scene::Scene() {
    camera = nullptr;
    background = nullptr;
}

Scene::~Scene() {
    for (auto& obj : gameObjects)
        delete obj;

    for (auto& light : lights)
        delete light;
}

void Scene::SetCamera(Camera* c) { camera = c; }

void Scene::SetBackground(Background* bg) { background = bg; }

void Scene::AddGameObject(GameObject* gameObj) {
    gameObjects.push_back(gameObj);
}

void Scene::AddLight(Light* light) {
    lights.push_back(light);
}
