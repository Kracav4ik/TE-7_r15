#include "InputManager.h"

#include "StateManager.h"

#include <SDL2/SDL_events.h>

InputManager::InputManager() {
    keyBind[SDLK_ESCAPE] = GameEvent::QuitGame;
    keyBind[SDLK_DOWN] = GameEvent::MoveDown;
    keyBind[SDLK_LEFT] = GameEvent::MoveLeft;
    keyBind[SDLK_RIGHT] = GameEvent::MoveRight;
    keyBind[SDLK_SPACE] = GameEvent::SpawnPiece;
    keyBind[SDLK_BACKSPACE] = GameEvent::RemovePieces;
    keyBind[SDLK_KP_ENTER] = GameEvent::LaunchStopGame;
    keyBind[SDLK_RETURN] = GameEvent::LaunchStopGame;
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
    StateManager::get()->handleEvent(event);
}
