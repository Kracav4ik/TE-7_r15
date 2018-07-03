#pragma once

#include <SDL2/SDL_rect.h>

#include "Renderable.h"

const int BLOCK_SIZE = 50;

class Block: public Renderable {
private:
    SDL_Rect rect;

public:
    explicit Block(const SDL_Rect& rect);
    explicit Block(int x, int y);

    const SDL_Rect& getRect() const;
    SDL_Rect& getRect();

    void shift();
    void translate(int x, int y);

    void render(SDL_Surface* pSurface) const override;
};
