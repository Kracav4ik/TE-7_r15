#include "Block.h"

#include <SDL2/SDL_surface.h>

Block::Block(const SDL_Rect& rect):rect(rect) {}

Block::Block(int x, int y, int w, int h): rect{x, y, w, h} {}

const SDL_Rect* Block::getRect() {
    return &rect;
}

void Block::process() {
    shift(100); //TODO: replace hardcoded width
}

void Block::render(SDL_Surface* surface) const {
    SDL_FillRect(surface, &rect, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
}

void Block::shift(int stop) {
    if (rect.y + BLOCK_SIZE < stop) {
        rect.y ++;
    }
}

void Block::forceShift(int stop) {
    if (rect.y + rect.h < stop) {
        rect.y += rect.h;
    }
}

void Block::left(int stop) {
    if (rect.x > stop) {
        rect.x -= rect.w;
    }
}

void Block::right(int stop) {
    if (rect.x + rect.w  < stop) {
        rect.x += rect.w;
    }
}
