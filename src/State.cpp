#include "State.h"

#include "GameEvent.h"

State::State(AppState currentState): currentState(currentState) {}

bool State::isGameState() const {
    return currentState == AppState::Game;
}

void State::process() {
}

void State::render(SDL_Surface* surface) const {
}

void State::handleEvent(GameEvent event) {
    auto range = callbacks.equal_range(event);
    for (auto it = range.first; it != range.second; ++it) {
        it->second();
    }
}

void State::subscribe(GameEvent event, CallbackType callback) {
    callbacks.emplace(event, std::move(callback));
}

bool State::handleKey(SDL_Keycode key) {
    if (keyBind.count(key)) {
        handleEvent(keyBind[key]);
        return true;
    }
    return false;
}

void State::addKeyBind(SDL_Keycode key, GameEvent event) {
    keyBind[key] = event;
}
