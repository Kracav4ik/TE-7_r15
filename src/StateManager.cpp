#include "StateManager.h"

#include "GameEvent.h"
#include "states/GameState.h"
#include "states/InGameMenuState.h"

StateManager::StateManager() : State(AppState::NoState) {
    subscribe(GameEvent::BeginGame, [this]() {
        pushState<GameState>();
    });
    subscribe(GameEvent::Pause, [this]() {
        pushState<InGameMenuState>();
    });
    subscribe(GameEvent::ExitToMainMenu, [this]() {
        switch (getCurrentState()->getCurrentState()){
            case AppState::MainMenu:break;
            case AppState::Game:
                popState();
                break;
            case AppState::InGameMenu:
                popState();
                popState();
                break;
            case AppState::NoState:break;
        }
    });
    subscribe(GameEvent::BackToGame, [this]() {
        popState();
    });
    subscribe(GameEvent::QuitGame, [this]() {
        quit = true;
    });
}

void StateManager::process() {
    getCurrentState()->process();
}

void StateManager::render(SDL_Surface* surface) const {
    int stop = states.size() - 1;
    for (; stop > 0; --stop) {
        if (!states[stop]->isTransparent()) {
            break;
        }
    }
    
    for (int i = stop; i < states.size(); ++i) {
        states[i]->render(surface);
    }
}

std::shared_ptr<State> StateManager::getCurrentState() {
    return states.back();
}

std::shared_ptr<State> StateManager::getCurrentState() const {
    return states.back();
}

void StateManager::pushState(const std::shared_ptr<State>& state) {
    states.emplace_back(state);
}

bool StateManager::handleKey(SDL_Keycode key) {
    if (State::handleKey(key)) {
        return true;
    }
    return getCurrentState()->handleKey(key);
}

void StateManager::popState() {
    states.pop_back();
}

void StateManager::handleEvent(GameEvent event) {
    State::handleEvent(event);
    getCurrentState()->handleEvent(event);
}

bool StateManager::isQuit() const {
    return quit;
}
