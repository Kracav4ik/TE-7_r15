#include "GameManager.h"

#include "GameObject.h"
#include "State.h"

GameManager::GameManager(State& state):state(state) {}

void GameManager::process() {
    if (state.isGameState()) {
        for (const auto& object : objects) {
            object->process();
        }
    }
}

void GameManager::addGameObject(std::shared_ptr<GameObject> object) {
    objects.push_back(object);
}
