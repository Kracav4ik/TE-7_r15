#pragma once

#include "Renderable.h"

class Menu: public Renderable {
public:
    void render(SDL_Surface* surface) const override;
};
