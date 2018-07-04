#include "Game.h"

void Game::addPiece(std::shared_ptr<Piece> piece) {
    activePiece = piece;

    pieces.push_back(piece);
}

void Game::process() {
    if (!activePiece) {
        return;
    }
    if (collideWithLevel(0, 1) == 0) {
        activePiece->translate(0, 1);
    } else {
        activePiece.reset();
    }
}

int Game::collideWithLevel(int dx, int dy) const {
    int collideDelta = 0;
    for (const auto& piece : pieces) {
        if (activePiece == piece) {
            continue;
        }
        for (const auto& b1 : activePiece->getBlocks()) {
            for (const auto& b2 : piece->getBlocks()) {
                Block newBlock = b1;
                newBlock.translate(dx, dy);
                if (SDL_HasIntersection(&newBlock.getRect(), &b2.getRect())) {
                    if (dx == 0) {
                        collideDelta = BLOCK_SIZE - std::abs(newBlock.getRect().y - b2.getRect().y);
                    } else {
                        collideDelta = BLOCK_SIZE - std::abs(newBlock.getRect().x - b2.getRect().x);
                    }
                    break;
                }
            }
        }
    }
    return collideDelta;
}

void Game::render(SDL_Surface* surface) const {
    for (const auto& piece : pieces) {
        piece->render(surface);
    }
}

void Game::moveRight() {
    if (activePiece) {
        int dx = collideWithLevel(BLOCK_SIZE, 0);
        activePiece->translate(BLOCK_SIZE - dx, 0);
    }
}

void Game::moveLeft() {
    if (activePiece) {
        int dx = collideWithLevel(-BLOCK_SIZE, 0);
        activePiece->translate(dx-BLOCK_SIZE, 0);
    }
}

void Game::moveDown() {
    if (activePiece) {
        int dy = collideWithLevel(0, BLOCK_SIZE);
        activePiece->translate(0, BLOCK_SIZE - dy);
    }
}

void Game::createRandomPiece(int x, int y) {
    addPiece(Piece::create(static_cast<Form>(std::rand() % static_cast<int>(Form::End))));
    activePiece->translate(x, y);
}

void Game::deleteAllPieces() {
    activePiece.reset();
    pieces.clear();
}
