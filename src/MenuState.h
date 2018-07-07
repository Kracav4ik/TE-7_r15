#pragma once

#include "State.h"
#include "Menu.h"

class MenuState: public State {
private:
    Menu menu;

public:
    MenuState();

    void process() override;

    void render(SDL_Surface* surface) const override;
};
