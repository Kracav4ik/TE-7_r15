#pragma once

#include "State.h"
#include "Game.h"

class GameState: public State {
private:
    Game game;

public:
    GameState();

    void process() override;

    void render(SDL_Surface* surface) const override;
};
