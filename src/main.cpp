#include "Block.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "GameManager.h"
#include "Piece.h"
#include "Game.h"

#include <SDL2/SDL.h>
#include <iostream>

const int SCREEN_WIDTH = 700;
const int SCREEN_HEIGHT = 500;
const char* const NAME = "SDL2 Window";

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    auto window = SDL_CreateWindow(NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    if (!window) {
        std::cerr << "Could not create window: " << SDL_GetError() << std::endl;
        return 1;
    }

    auto& input = InputManager::get();
    auto& gameManager = GameManager::get();
    auto& render = RenderManager::get();

    auto game = std::make_shared<Game>();
    game->createRandomPiece(SCREEN_WIDTH/2, 0);
    bool quit = false;
    input.subscribe(GameEvent::QuitGame, [&quit]() {
        quit = true;
    });
    input.subscribe(GameEvent::MoveRight, [&game]() {
        game->moveRight();
    });
    input.subscribe(GameEvent::SpawnPiece, [&game]() {
        game->createRandomPiece(SCREEN_WIDTH/2, 0);
    });
    input.subscribe(GameEvent::MoveDown, [&game]() {
        game->moveDown();
    });
    input.subscribe(GameEvent::MoveLeft, [&game]() {
        game->moveLeft();
    });

    render.addRenderable(game);
    gameManager.addGameObject(game);

    auto screenSurface = SDL_GetWindowSurface(window);
    while (!quit) {
        input.handleInput();
        gameManager.process();
        render.render(screenSurface, window);
        SDL_Delay(20);
    }

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
