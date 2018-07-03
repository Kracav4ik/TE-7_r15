#include "Game.h"

void Game::addPiece(std::shared_ptr<Piece> piece) {
    if (!activePiece) {
        activePiece = piece;
    }
    pieces.push_back(piece);
}

void Game::process() {
    if (!activePiece) {
        return;
    } 
    for (const auto& p2 : pieces) {
        if (activePiece == p2) {
            continue;
        }
        for (const auto& b1 : activePiece->getBlocks()) {
            bool collided = false;
            for (const auto& b2 : p2->getBlocks()) {
                Block newBlock = b1;
                newBlock.shift();
                if (SDL_HasIntersection(&newBlock.getRect(), &b2.getRect())) {
                    collided = true;
                    break;
                }
            }
            if (!collided) {
                activePiece->translate(0, 1);
            } else {
                activePiece.reset();
            }
        }
    }
}

void Game::render(SDL_Surface* surface) const {
    for (const auto& piece : pieces) {
        piece->render(surface);
    }
}

std::shared_ptr<Piece> Game::getActivePiece() {
    return activePiece;
}
