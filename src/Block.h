#pragma once

#include <SDL2/SDL_rect.h>

#include "Renderable.h"

const int BLOCK_SIZE = 50;

class Block: public Renderable {
private:
    SDL_Rect rect;
    SDL_Color color;

public:
    explicit Block(const SDL_Rect& rect, SDL_Color color);
    explicit Block(int x, int y, SDL_Color color);

    const SDL_Rect& getRect() const;
    SDL_Rect& getRect();
    SDL_Point getRightBottom();
    SDL_Point getTopLeft();

    void translate(int dx, int dy);

    void render(SDL_Surface* pSurface) const override;
};
