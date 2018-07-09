#pragma once

#include "State.h"
#include "Menu.h"

class InGameMenuState : public State {
private:
    Menu inGameMenu;

public:
    InGameMenuState();
    void render(SDL_Surface* surface) const override;
};
