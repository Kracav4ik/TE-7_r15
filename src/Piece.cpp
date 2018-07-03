#include "Piece.h"

#include <memory>

Piece::Piece(std::vector<Block>&& blocks): blocks(std::move(blocks)) {}

std::shared_ptr<Piece> Piece::create(Form form) {
    std::vector<Block> newBlocks;
    newBlocks.emplace_back(0,0);
    switch (form) {
        case Form::LBlock:
            newBlocks.emplace_back(0, BLOCK_SIZE);
            newBlocks.emplace_back(0, 2*BLOCK_SIZE);
            newBlocks.emplace_back(BLOCK_SIZE, 2*BLOCK_SIZE);
            break;
        case Form::JBlock:
            newBlocks.emplace_back(0, BLOCK_SIZE);
            newBlocks.emplace_back(0, 2*BLOCK_SIZE);
            newBlocks.emplace_back(-BLOCK_SIZE, 2*BLOCK_SIZE);
            break;
        case Form::IBlock:
            newBlocks.emplace_back(0, BLOCK_SIZE);
            newBlocks.emplace_back(0, 2*BLOCK_SIZE);
            newBlocks.emplace_back(0, 3*BLOCK_SIZE);
            break;
        case Form::TBlock:
            newBlocks.emplace_back(BLOCK_SIZE, 0);
            newBlocks.emplace_back(2*BLOCK_SIZE, 0);
            newBlocks.emplace_back(BLOCK_SIZE, BLOCK_SIZE);
            break;
        case Form::Square:
            newBlocks.emplace_back(BLOCK_SIZE,0);
            newBlocks.emplace_back(0, BLOCK_SIZE);
            newBlocks.emplace_back(BLOCK_SIZE, BLOCK_SIZE);
            break;
        case Form::RightTurn:
            newBlocks.emplace_back(BLOCK_SIZE, 0);
            newBlocks.emplace_back(BLOCK_SIZE, -BLOCK_SIZE);
            newBlocks.emplace_back(2*BLOCK_SIZE, -BLOCK_SIZE);
            break;
        case Form::LeftTurn:
            newBlocks.emplace_back(BLOCK_SIZE, 0);
            newBlocks.emplace_back(BLOCK_SIZE, BLOCK_SIZE);
            newBlocks.emplace_back(2*BLOCK_SIZE, BLOCK_SIZE);
            break;
    }
    return std::shared_ptr<Piece>(new Piece(std::move(newBlocks)));
}

void Piece::render(SDL_Surface* surface) const {
    for (const auto& block : blocks) {
        block.render(surface);
    }
}

void Piece::translate(int x, int y) {
    for (auto& block : blocks) {
        block.translate(x, y);
    }
}

const std::vector<Block>& Piece::getBlocks() const {
    return blocks;
}
