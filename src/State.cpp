#include "State.h"

State::State(GameState currentState): currentState(currentState) {}

void State::changeState() {
    if (currentState == GameState::Menu) {
        currentState = GameState::Game;
    } else {
        currentState = GameState::Menu;
    }
}

bool State::isGameState() const {
    return currentState == GameState::Game;
}
