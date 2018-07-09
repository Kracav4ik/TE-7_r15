#pragma once

#include "MenuStateBase.h"

class InGameMenuState : public MenuStateBase {
public:
    InGameMenuState();

    bool isTransparent() const override;
    void render(SDL_Surface* surface) const override;
};
