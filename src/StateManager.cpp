#include "StateManager.h"

#include "GameEvent.h"
#include "GameState.h"

StateManager::StateManager() : State(AppState::NoState) {
    addKeyBind(SDLK_ESCAPE, GameEvent::QuitGame);
    addKeyBind(SDLK_KP_ENTER, GameEvent::LaunchStopGame);
    addKeyBind(SDLK_RETURN, GameEvent::LaunchStopGame);

    subscribe(GameEvent::LaunchStopGame, [this]() {
        if (getCurrentState()->isGameState()) {
            popState();
        } else {
            pushState<GameState>();
        }
    });
    subscribe(GameEvent::QuitGame, [this]() {
        quit = true;
    });
}

void StateManager::process() {
    getCurrentState()->process();
}

void StateManager::render(SDL_Surface* surface) const {
    getCurrentState()->render(surface);
}

std::shared_ptr<State> StateManager::getCurrentState() {
    return states.top();
}

std::shared_ptr<State> StateManager::getCurrentState() const {
    return states.top();
}

void StateManager::pushState(const std::shared_ptr<State>& state) {
    states.push(state);
}

bool StateManager::handleKey(SDL_Keycode key) {
    if (State::handleKey(key)) {
        return true;
    }
    return getCurrentState()->handleKey(key);
}

void StateManager::popState() {
    states.pop();
}

void StateManager::handleEvent(GameEvent event) {
    State::handleEvent(event);
    getCurrentState()->handleEvent(event);
}

bool StateManager::isQuit() const {
    return quit;
}
