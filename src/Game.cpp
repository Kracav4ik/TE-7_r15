#include "Game.h"

#include <algorithm>

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

int manhDist(const SDL_Point& point) {
    return std::abs(point.x) + std::abs(point.y);
}

void Game::addPiece(std::shared_ptr<Piece> piece) {
    activePiece = piece;

    pieces.push_back(piece);
}

void Game::process() {
    if (!activePiece) {
        return;
    }
    static bool canStop = true;
    if (collideWithLevel(0, 1) == 0 && activePiece->getBottom() < SCREEN_HEIGHT) {
        activePiece->translate(0, 1);
        canStop = false;
    } else {
        activePiece.reset();
        if (!canStop) {
            createRandomPiece(SCREEN_WIDTH/2, 0);
        }
        canStop = true;
    }
}

int Game::collideWithLevel(int dx, int dy) const {
    std::vector<SDL_Point> collideDelta;
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
                        collideDelta.emplace_back(SDL_Point{0, BLOCK_SIZE - std::abs(newBlock.getRect().y - b2.getRect().y)});
                    } else {
                        collideDelta.emplace_back(SDL_Point{BLOCK_SIZE - std::abs(newBlock.getRect().x - b2.getRect().x), 0});
                    }
                }
            }
        }
    }
    if (collideDelta.empty()) {
        return 0;
    } else {
        auto cmp = [](const SDL_Point& p1, const SDL_Point& p2) {
            return manhDist(p1) > manhDist(p2);
        };
        const SDL_Point& res = *std::min_element(collideDelta.begin(), collideDelta.end(), cmp);
        return manhDist(res);
    };
}

void Game::render(SDL_Surface* surface) const {
    for (const auto& piece : pieces) {
        piece->render(surface);
    }
}

void Game::moveRight() {
    if (activePiece) {
        int dx = collideWithLevel(BLOCK_SIZE, 0);
        if (activePiece->getRight() < SCREEN_WIDTH) {
            activePiece->translate(BLOCK_SIZE - dx, 0);
        }
    }
}

void Game::moveLeft() {
    if (activePiece) {
        int dx = collideWithLevel(-BLOCK_SIZE, 0);
        if (activePiece->getLeft() > 0) {
            activePiece->translate(dx - BLOCK_SIZE, 0);
        }
    }
}

void Game::moveDown() {
    if (activePiece) {
        int dy = collideWithLevel(0, BLOCK_SIZE);
        if (activePiece->getBottom() < SCREEN_HEIGHT - BLOCK_SIZE) {
            activePiece->translate(0, BLOCK_SIZE - dy);
        } else {
            activePiece->translate(0, SCREEN_HEIGHT - activePiece->getBottom());
        }
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
