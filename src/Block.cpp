#include "Block.h"
#include <tuple>

Block::Block(const SDL_Rect& rect):rect(rect) {}

Block::Block(const Block& other):rect(other.rect) {}

Block::Block(int x, int y, int w, int h): rect(SDL_Rect()) {
    std::tie(rect.x, rect.y, rect.w, rect.h) = std::make_tuple<int&, int&, int&, int&>(x, y, w, h);
}

Block& Block::operator=(Block&& other) {
    if (&other != this) {
        std::tie((rect.x), (rect.y), (rect.w), (rect.h)) =
            std::make_tuple<int&, int&, int&, int&>(other.rect.x, other.rect.y, other.rect.w, other.rect.h);

    }
    return *this;
}

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
