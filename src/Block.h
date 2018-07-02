#pragma once

#include <SDL2/SDL_rect.h>

class Block {
private:
    SDL_Rect rect;
public:
    explicit Block(const SDL_Rect& rect);
    explicit Block(const Block& other);
    explicit Block(int x, int y, int w, int h);

    Block& operator=(Block&& other);

    const SDL_Rect* getRect();
};
