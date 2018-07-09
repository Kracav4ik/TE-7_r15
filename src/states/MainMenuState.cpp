#include "MainMenuState.h"

#include <SDL2/SDL_surface.h>

MainMenuState::MainMenuState() : MenuStateBase(AppState::MainMenu) {
    menu.addButton("Start", GameEvent::BeginGame);
    menu.addButton("Exit", GameEvent::QuitGame);

    addKeyBind(SDLK_ESCAPE, GameEvent::QuitGame);
}

void MainMenuState::render(SDL_Surface* surface) const {
    SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
    menu.render(surface);
}
