#include "TransparentState.h"

TransparentState::TransparentState() : State(AppState::Transparent), transparent(true) {
    transparent.addButton("Continue", GameEvent::BackToGame);
    transparent.addButton("Main menu", GameEvent::ExitToMainMenu);
    addKeyBind(SDLK_ESCAPE, GameEvent::BackToGame);
    addKeyBind(SDLK_DOWN, GameEvent::MenuMoveDown);
    addKeyBind(SDLK_UP, GameEvent::MenuMoveUp);
    addKeyBind(SDLK_RETURN, GameEvent::MenuSelect);
    addKeyBind(SDLK_KP_ENTER, GameEvent::MenuSelect);

    subscribe(GameEvent::MenuMoveDown, [this]() {
        transparent.menuMoveDown();
    });
    subscribe(GameEvent::MenuMoveUp, [this]() {
        transparent.menuMoveUp();
    });
    subscribe(GameEvent::MenuSelect, [this]() {
        transparent.pressSelectedButton();
    });
}

void TransparentState::render(SDL_Surface* surface) const {
    transparent.render(surface);
}
