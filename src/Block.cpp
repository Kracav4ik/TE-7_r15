#include "Block.h"

#include <SDL2/SDL_surface.h>

Block::Block(const SDL_Rect& rect, SDL_Color color)
    :rect(rect), color(color) {}

Block::Block(int x, int y, SDL_Color color)
    : rect{x, y, BLOCK_SIZE, BLOCK_SIZE}, color(color) {}

const SDL_Rect& Block::getRect() const {
    return rect;
}

SDL_Rect& Block::getRect() {
    return rect;
}

void Block::render(SDL_Surface* surface) const {
    SDL_FillRect(surface, &rect, SDL_MapRGBA(surface->format, color.r, color.g, color.b, color.a));
}

void Block::translate(int dx, int dy) {
    rect.x += dx;
    rect.y += dy;
}
