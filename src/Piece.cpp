#include "Piece.h"

#include <memory>

Piece::Piece(std::vector<Block>&& blocks): blocks(std::move(blocks)) {}

std::shared_ptr<Piece> Piece::create(Form form) {
    std::vector<Block> newBlocks;
    static std::array<SDL_Color, 12> colors = {
        SDL_Color{0xFF, 0, 0, 0xFF},
        SDL_Color{0, 0xFF, 0, 0xFF},
        SDL_Color{0xFF, 0xFF, 0, 0xFF},
        SDL_Color{0, 0, 0xFF, 0xFF},
        SDL_Color{0xFF, 0, 0xFF, 0xFF},
        SDL_Color{0, 0xFF, 0xFF, 0xFF},
        SDL_Color{0x80, 0, 0, 0xFF},
        SDL_Color{0, 0x80, 0, 0xFF},
        SDL_Color{0x80, 0x80, 0, 0xFF},
        SDL_Color{0, 0, 0x80, 0xFF},
        SDL_Color{0x80, 0, 0x80, 0xFF},
        SDL_Color{0, 0x80, 0x80, 0xFF},
    };
    SDL_Color color = colors[std::rand()%12];
    newBlocks.emplace_back(0,0, color);
    switch (form) {
        case Form::LBlock:
            newBlocks.emplace_back(0, BLOCK_SIZE, color);
            newBlocks.emplace_back(0, 2*BLOCK_SIZE, color);
            newBlocks.emplace_back(BLOCK_SIZE, 2*BLOCK_SIZE, color);
            break;
        case Form::JBlock:
            newBlocks.emplace_back(0, BLOCK_SIZE, color);
            newBlocks.emplace_back(0, 2*BLOCK_SIZE, color);
            newBlocks.emplace_back(-BLOCK_SIZE, 2*BLOCK_SIZE, color);
            break;
        case Form::IBlock:
            newBlocks.emplace_back(0, BLOCK_SIZE, color);
            newBlocks.emplace_back(0, 2*BLOCK_SIZE, color);
            newBlocks.emplace_back(0, 3*BLOCK_SIZE, color);
            break;
        case Form::TBlock:
            newBlocks.emplace_back(BLOCK_SIZE, 0, color);
            newBlocks.emplace_back(2*BLOCK_SIZE, 0, color);
            newBlocks.emplace_back(BLOCK_SIZE, BLOCK_SIZE, color);
            break;
        case Form::Square:
            newBlocks.emplace_back(BLOCK_SIZE,0, color);
            newBlocks.emplace_back(0, BLOCK_SIZE, color);
            newBlocks.emplace_back(BLOCK_SIZE, BLOCK_SIZE, color);
            break;
        case Form::RightTurn:
            newBlocks.emplace_back(BLOCK_SIZE, 0, color);
            newBlocks.emplace_back(BLOCK_SIZE, -BLOCK_SIZE, color);
            newBlocks.emplace_back(2*BLOCK_SIZE, -BLOCK_SIZE, color);
            break;
        case Form::LeftTurn:
            newBlocks.emplace_back(BLOCK_SIZE, 0, color);
            newBlocks.emplace_back(BLOCK_SIZE, BLOCK_SIZE, color);
            newBlocks.emplace_back(2*BLOCK_SIZE, BLOCK_SIZE, color);
            break;
    }
    return std::shared_ptr<Piece>(new Piece(std::move(newBlocks)));
}

void Piece::render(SDL_Surface* surface) const {
    for (const auto& block : blocks) {
        block.render(surface);
    }
}

void Piece::translate(int dx, int dy) {
    for (auto& block : blocks) {
        block.translate(dx, dy);
    }
}

const std::vector<Block>& Piece::getBlocks() const {
    return blocks;
}
