#include "Button.h"

#include "GameEvent.h"
#include <iostream>

#include <SDL2/SDL_ttf.h>

SDL_Rect operator+(const SDL_Rect& r, const SDL_Point& p) { return {r.x + p.x, r.y + p.y, r.w, r.h}; }

void Button::render(SDL_Surface* surface) const {
    SDL_Rect button = {pos.x, pos.y, BUTTON_SIZE.x, BUTTON_SIZE.y};

    if (highlight){
        SDL_Rect highlightButton = {pos.x - 5, pos.y - 5, BUTTON_SIZE.x + 10, BUTTON_SIZE.y + 10};
        SDL_FillRect(surface, &highlightButton, SDL_MapRGB(surface->format, highlightColor.r, highlightColor.g, highlightColor.b));
    }
    SDL_FillRect(surface, &button, SDL_MapRGB(surface->format, buttonColor.r, buttonColor.g, buttonColor.b));

    if (SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, text.c_str(), textColor)) {
        SDL_Rect text = button + SDL_Point{(button.w - surfaceMessage->w) /2, (button.h - surfaceMessage->h) /2};
        SDL_BlitSurface(surfaceMessage, nullptr, surface, &text);
        //perhaps we can reuse it, but I assume not for simplicity.
        SDL_FreeSurface(surfaceMessage);
    } else {
        std::string error = SDL_GetError();
        std::cout << "SDL error " << error;
    }
}

Button::Button(std::string text, GameEvent event)
    : font(TTF_OpenFont("FreeSans.ttf", 60))
    , pos({0, 0})
    , text(std::move(text))
    , event(event)
{}

Button::~Button() {
    TTF_CloseFont(font);
}

void Button::setCenter(const SDL_Point& centerPos) {
    pos = {centerPos.x - BUTTON_SIZE.x/2, centerPos.y - BUTTON_SIZE.y/2};
}

GameEvent Button::getEvent() const {
    return event;
}
