#include <SDL2/SDL.h>

#include <iostream>

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    auto window = SDL_CreateWindow("SDL2 Window", 100, 100, 640, 480, 0);

    if (!window) {
        std::cerr << "Could not create window: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Delay(3000);

    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
