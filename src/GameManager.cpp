#include "GameManager.h"

#include "GameObject.h"

GameManager::GameManager() = default;

void GameManager::process() {
    for (GameObject* object : objects) {
        object->process();
    }
}

void GameManager::addGameObject(GameObject* object) {
    objects.push_back(object);
}
