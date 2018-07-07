#include "GameState.h"

#include "GameEvent.h"

extern const int SCREEN_WIDTH;

GameState::GameState(): State(AppState::Game) {
    addKeyBind(SDLK_DOWN, GameEvent::MoveDown);
    addKeyBind(SDLK_LEFT, GameEvent::MoveLeft);
    addKeyBind(SDLK_RIGHT, GameEvent::MoveRight);
    addKeyBind(SDLK_SPACE, GameEvent::SpawnPiece);
    addKeyBind(SDLK_BACKSPACE, GameEvent::RemovePieces);

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
