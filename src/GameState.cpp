#include "GameState.h"

#include "GameEvent.h"

extern const int SCREEN_WIDTH;

GameState::GameState(): State(AppState::Game) {
    game.createRandomPiece(SCREEN_WIDTH/2, 0);

    subscribe(GameEvent::MoveRight, [this]() {
        game.moveRight();
    });
    subscribe(GameEvent::MoveDown, [this]() {
        game.moveDown();
    });
    subscribe(GameEvent::MoveLeft, [this]() {
        game.moveLeft();
    });
    subscribe(GameEvent::RemovePieces, [this]() {
        game.deleteAllPieces();
    });
    subscribe(GameEvent::SpawnPiece, [this]() {
        game.createRandomPiece(SCREEN_WIDTH/2, 0);
    });
}

void GameState::process() {
    game.process();
}

void GameState::render(SDL_Surface* surface) const {
    game.render(surface);
}
