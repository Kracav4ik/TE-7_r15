#pragma once

enum class GameState {
    Menu,
    Game,
};

class State {
private:
    GameState currentState;

public:
    explicit State(GameState currentState);
    void changeState();

    bool isGameState() const;
};
