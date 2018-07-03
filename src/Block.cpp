#include "Block.h"

#include <SDL2/SDL_surface.h>

Block::Block(const SDL_Rect& rect):rect(rect) {}

Block::Block(int x, int y): rect{x, y, BLOCK_SIZE, BLOCK_SIZE} {}

const SDL_Rect& Block::getRect() const {
    return rect;
}

SDL_Rect& Block::getRect() {
    return rect;
}

void Block::render(SDL_Surface* surface) const {
    SDL_FillRect(surface, &rect, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
}

void Block::shift() {
    rect.y++;
}

void Block::translate(int x, int y) {
    rect.x += x;
    rect.y += y;
}
