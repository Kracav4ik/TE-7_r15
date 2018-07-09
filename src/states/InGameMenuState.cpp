#include "InGameMenuState.h"

InGameMenuState::InGameMenuState() : State(AppState::InGameMenu), inGameMenu(true) {
    inGameMenu.addButton("Continue", GameEvent::BackToGame);
    inGameMenu.addButton("Main menu", GameEvent::ExitToMainMenu);
    addKeyBind(SDLK_ESCAPE, GameEvent::BackToGame);
    addKeyBind(SDLK_DOWN, GameEvent::MenuMoveDown);
    addKeyBind(SDLK_UP, GameEvent::MenuMoveUp);
    addKeyBind(SDLK_RETURN, GameEvent::MenuSelect);
    addKeyBind(SDLK_KP_ENTER, GameEvent::MenuSelect);

    subscribe(GameEvent::MenuMoveDown, [this]() {
        inGameMenu.menuMoveDown();
    });
    subscribe(GameEvent::MenuMoveUp, [this]() {
        inGameMenu.menuMoveUp();
    });
    subscribe(GameEvent::MenuSelect, [this]() {
        inGameMenu.pressSelectedButton();
    });
}

void InGameMenuState::render(SDL_Surface* surface) const {
    inGameMenu.render(surface);
}
