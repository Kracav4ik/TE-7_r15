#include "InputManager.h"

#include <SDL2/SDL_events.h>

InputManager::InputManager() {
    keyBind[SDLK_ESCAPE] = GameEvent::QuitGame;
    keyBind[SDLK_DOWN] = GameEvent::MoveDown;
    keyBind[SDLK_LEFT] = GameEvent::MoveLeft;
    keyBind[SDLK_RIGHT] = GameEvent::MoveRight;
    keyBind[SDLK_SPACE] = GameEvent::SpawnPiece;
}

void InputManager::handleInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            handleEvent(GameEvent::QuitGame);
        }
        else if (event.type == SDL_KEYDOWN) {
            auto key = event.key.keysym.sym;
            if (keyBind.count(key)) {
                handleEvent(keyBind[key]);
            }
        }
    }
}

void InputManager::handleEvent(GameEvent event) {
    auto range = callbacks.equal_range(event);
    for (auto it = range.first; it != range.second; ++it) {
        it->second();
    }
}

void InputManager::subscribe(GameEvent event, CallbackType callback) {
    callbacks.emplace(event, std::move(callback));
}
