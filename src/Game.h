#pragma once

#include "Piece.h"
#include "GameObject.h"

class Game: public GameObject, public Renderable {
private:
    std::vector<std::shared_ptr<Piece>> pieces;
    std::shared_ptr<Piece> activePiece;

public:
    void process() override;

    void createRandomPiece(int x, int y);

    void moveRight();
    void moveLeft();
    void moveDown();

    void render(SDL_Surface* surface) const override;

    void addPiece(std::shared_ptr<Piece> piece);

    int collideWithLevel(int dx, int dy) const;
};
