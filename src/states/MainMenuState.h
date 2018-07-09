#pragma once

#include "MenuStateBase.h"

class MainMenuState: public MenuStateBase {
public:
    MainMenuState();
    void render(SDL_Surface* surface) const override;
};
