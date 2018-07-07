#pragma once

#include "Singleton.h"
#include "GameEvent.h"

#include <map>
#include <SDL2/SDL_keycode.h>

class InputManager: public Singleton<InputManager> {
private:
    friend class Singleton<InputManager>;
    InputManager();
    std::map<SDL_Keycode, GameEvent> keyBind;
    void handleEvent(GameEvent event);

public:
    void handleInput();
};
