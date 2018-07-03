#include "GameManager.h"

#include "GameObject.h"

GameManager::GameManager() = default;

void GameManager::process() {
    for (const auto& object : objects) {
        object->process();
    }
}

void GameManager::addGameObject(std::shared_ptr<GameObject> object) {
    objects.push_back(object);
}
