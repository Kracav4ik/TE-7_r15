#include "Block.h"
#include <tuple>

Block::Block(const SDL_Rect& rect):rect(rect) {}

Block::Block(int x, int y, int w, int h): rect{x, y, w, h} {}

const SDL_Rect* Block::getRect() {
    return &rect;
}

void Block::shift(int stop) {
    if (rect.y + BLOCK_SIZE < stop) {
        rect.y ++;
    }
}

void Block::force_shift(int stop) {
    if (rect.y + BLOCK_SIZE < stop) {
        rect.y += BLOCK_SIZE;
    }
}

void Block::left(int stop) {
    if (rect.x > stop) {
        rect.x -= BLOCK_SIZE;
    }
}

void Block::right(int stop) {
    if (rect.x + BLOCK_SIZE  < stop) {
        rect.x += BLOCK_SIZE;
    }
}
