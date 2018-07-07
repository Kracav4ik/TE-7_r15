#pragma once

#include "Singleton.h"

#include <vector>
#include <memory>

class GameObject;
class State;

class GameManager: public Singleton<GameManager> {
private:
    friend class Singleton<GameManager>;
    GameManager();
    std::vector<std::shared_ptr<GameObject>> objects;

public:
    void process();
    void addGameObject(std::shared_ptr<GameObject> object);
};
