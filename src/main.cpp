#include "Block.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "GameManager.h"

#include <SDL2/SDL.h>
#include <iostream>

const int SCREEN_WIDTH = 650;
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
    auto& game = GameManager::get();
    auto& render = RenderManager::get();

    Block activeBlock(0, 0, BLOCK_SIZE, BLOCK_SIZE);
    bool quit = false;
    input.subscribe(GameEvent::QuitGame, [&quit]() {
        quit = true;
    });
    input.subscribe(GameEvent::MoveRight, [&activeBlock]() {
        activeBlock.right(SCREEN_WIDTH);
    });
    input.subscribe(GameEvent::MoveDown, [&activeBlock]() {
        activeBlock.forceShift(SCREEN_HEIGHT);
    });
    input.subscribe(GameEvent::MoveLeft, [&activeBlock]() {
        activeBlock.left(0);
    });

    render.addRenderable(&activeBlock);
    game.addGameObject(&activeBlock);

    auto screenSurface = SDL_GetWindowSurface(window);
    while (!quit) {
        input.handleInput();
        game.process();
        render.render(screenSurface, window);
        SDL_Delay(20);
    }

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
