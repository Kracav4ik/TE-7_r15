#include "Menu.h"

#include <SDL2/SDL_ttf.h>
#include <iostream>

SDL_Rect operator+(const SDL_Rect& r, const SDL_Point& p) { return {r.x + p.x, r.y + p.y, r.w, r.h}; }

const SDL_Point BUTTON_SIZE = {300, 100};

void Menu::render(SDL_Surface* surface) const {
    SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));

    SDL_Rect button = {(surface->w - BUTTON_SIZE.x) / 2, (surface->h - BUTTON_SIZE.y) / 2, BUTTON_SIZE.x, BUTTON_SIZE.y};

    SDL_FillRect(surface, &button, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0x00));

    SDL_Point textMargin = {10, 10};

    TTF_Font* Sans = TTF_OpenFont("FreeSans.ttf", 60);
    SDL_Color color = {0, 0, 0};

    if (SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "Start game", color)) {
        SDL_Rect text = button + textMargin;
        SDL_BlitSurface(surfaceMessage, nullptr, surface, &text);
        //perhaps we can reuse it, but I assume not for simplicity.
        SDL_FreeSurface(surfaceMessage);
    } else {
        std::string error = SDL_GetError();
        std::cout << "SDL error " << error;
    }

    TTF_CloseFont(Sans);
}
