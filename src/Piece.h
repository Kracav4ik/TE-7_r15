#pragma once

#include "Block.h"

#include <vector>
#include <memory>

enum class Form {
    LBlock,
    JBlock,
    IBlock,
    TBlock,
    Square,
    RightTurn,
    LeftTurn,
    End,
};

class Piece: public Renderable {
private:
    std::vector<Block> blocks;
    explicit Piece(std::vector<Block>&& blocks);

public:
    static std::shared_ptr<Piece> create(Form form);

    void render(SDL_Surface* surface) const override;

    void translate(int dx, int dy);

    const std::vector<Block>& getBlocks() const;

    int getRight();
    int getLeft();
    int getBottom();
};
