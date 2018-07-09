#pragma once

#include "State.h"
#include "Menu.h"

class MainMenuState: public State {
private:
    Menu menu;

public:
    MainMenuState();

    void process() override;

    void render(SDL_Surface* surface) const override;
};
