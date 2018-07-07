#pragma once

#include "Renderable.h"
#include "GameEvent.h"

#include <string>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_ttf.h>

const SDL_Point BUTTON_SIZE = {300, 100};

class Button : public Renderable {
private:
    TTF_Font* font;
    SDL_Point textMargin;
    SDL_Point pos;
    std::string text;
    GameEvent event;
    SDL_Color buttonColor = {0xFF, 0xFF, 0, 0xFF};
    SDL_Color textColor = {0, 0, 0, 0xFF};
    SDL_Color highlightColor = {0xFF, 0, 0, 0xFF};

public:
    explicit Button(std::string text, GameEvent event);
    virtual ~Button();

    GameEvent getEvent() const;
    bool highlight = false;
    void setCenter(const SDL_Point& centerPos);
    void render(SDL_Surface* surface) const override;
};
