#pragma once

#include <SDL2/SDL_rect.h>

const int BLOCK_SIZE = 50;

class Block {
private:
    SDL_Rect rect;
public:
    explicit Block(const SDL_Rect& rect);
    explicit Block(int x, int y, int w, int h);

    const SDL_Rect* getRect();

    void shift(int stop);

    void left(int stop);

    void right(int stop);

    void force_shift(int stop);
};
