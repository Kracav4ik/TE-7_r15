#pragma once

#include "Singleton.h"
#include "GameEvent.h"

#include <functional>
#include <map>
#include <SDL2/SDL_keycode.h>

class InputManager: public Singleton<InputManager> {
public:
    using CallbackType = std::function<void()>;

private:
    friend class Singleton<InputManager>;
    InputManager();
    std::map<SDL_Keycode, GameEvent> keyBind;
    std::multimap<GameEvent, CallbackType> callbacks;

    void handleEvent(GameEvent event);

public:
    void subscribe(GameEvent event, CallbackType callback);
    void handleInput();
};
