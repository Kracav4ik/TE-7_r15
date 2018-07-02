#pragma once

#include "Singleton.h"

#include <vector>

class GameObject;

class GameManager: public Singleton<GameManager> {
private:
    friend class Singleton<GameManager>;
    GameManager();
    std::vector<GameObject*> objects;

public:
    void process();
    void addGameObject(GameObject* object);
};
