#include "InputManager.h"

#include "StateManager.h"

#include <SDL2/SDL_events.h>

InputManager::InputManager() = default;

void InputManager::handleInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            handleEvent(GameEvent::QuitGame);
        }
        else if (event.type == SDL_KEYDOWN) {
            auto key = event.key.keysym.sym;
            StateManager::get()->handleKey(key);
        }
    }
}

void InputManager::handleEvent(GameEvent event) {
    StateManager::get()->handleEvent(event);
}
