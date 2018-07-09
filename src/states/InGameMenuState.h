#pragma once

#include "MenuStateBase.h"

class InGameMenuState : public MenuStateBase {
public:
    InGameMenuState();
    void render(SDL_Surface* surface) const override;
};
