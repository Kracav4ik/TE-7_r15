#include "Block.h"
#include "InputManager.h"
#include "RenderManager.h"
#include "GameManager.h"
#include "Piece.h"
#include "Game.h"
#include "StateManager.h"
#include "MenuState.h"

#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_ttf.h>

extern const int SCREEN_WIDTH = 700;
extern const int SCREEN_HEIGHT = 500;
const char* const NAME = "SDL2 Window";

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    auto window = SDL_CreateWindow(NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    if (!window) {
        std::cerr << "Could not create window: " << SDL_GetError() << std::endl;
        return 1;
    }

    auto input = InputManager::get();
    auto gameManager = GameManager::get();
    auto render = RenderManager::get();
    auto state = StateManager::get();

    state->pushState(std::static_pointer_cast<State>(std::make_shared<MenuState>()));

    render->addRenderable(state);
    gameManager->addGameObject(state);

    auto screenSurface = SDL_GetWindowSurface(window);
    while (!state->isQuit()) {
        input->handleInput();
        gameManager->process();
        render->render(screenSurface, window);
        SDL_Delay(20);
    }

    SDL_DestroyWindow(window);

    TTF_Quit();
    SDL_Quit();

    return 0;
}
