#pragma once

#include "Singleton.h"
#include "GameEvent.h"

class InputManager: public Singleton<InputManager> {
private:
    friend class Singleton<InputManager>;
    InputManager();
    void handleEvent(GameEvent event);

public:
    void handleInput();
};
