#include <SDL2/SDL.h>

#include <iostream>
#include "Block.h"

const int SCREEN_WIDTH = 650;
const int SCREEN_HEIGHT = 500;
const char* const NAME = "SDL2 Window";

bool handleInput(Block& active_block);
void process(Block& activeBlock);
void render(Block& block, SDL_Surface* screenSurface, SDL_Window* window);

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    auto window = SDL_CreateWindow(NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

    if (!window) {
        std::cerr << "Could not create window: " << SDL_GetError() << std::endl;
        return 1;
    }

    Block activeBlock(0, 0, BLOCK_SIZE, BLOCK_SIZE);
    bool quit = false;
    auto screenSurface = SDL_GetWindowSurface(window);
    while (!quit) {
        quit = handleInput(activeBlock);
        process(activeBlock);
        render(activeBlock, screenSurface, window);
        SDL_Delay(20);
    }

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}

bool handleInput(Block& active_block) {
    bool quit = false;
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            quit = true;
        }
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_LEFT:
                    active_block.left(0);
                    break;
                case SDLK_RIGHT:
                    active_block.right(SCREEN_WIDTH);
                    break;
                case SDLK_DOWN:
                    active_block.force_shift(SCREEN_HEIGHT);
                    break;
                default:
                    break;
            }
        }
    }
    return quit;
}

void process(Block& activeBlock) {
    activeBlock.shift(SCREEN_HEIGHT);
}

void render(Block& block, SDL_Surface* screenSurface, SDL_Window* window) {
    SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));
    SDL_FillRect(screenSurface, block.getRect(), SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(window);
}
