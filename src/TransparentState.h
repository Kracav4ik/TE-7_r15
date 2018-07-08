#pragma once

#include "State.h"
#include "Menu.h"

class TransparentState : public State {
private:
    Menu transparent;

public:
    TransparentState();
    void render(SDL_Surface* surface) const override;
};
