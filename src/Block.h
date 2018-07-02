#pragma once

#include <SDL2/SDL_rect.h>

#include "GameObject.h"
#include "Renderable.h"

const int BLOCK_SIZE = 50;

class Block: public Renderable, public GameObject {
private:
    SDL_Rect rect;

public:
    explicit Block(const SDL_Rect& rect);
    explicit Block(int x, int y, int w, int h);

    const SDL_Rect* getRect();

    void shift(int stop);

    void left(int stop);

    void right(int stop);

    void forceShift(int stop);

    void process() override;

    void render(SDL_Surface* pSurface) const override;
};
