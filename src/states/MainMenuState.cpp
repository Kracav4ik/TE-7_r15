#include "MainMenuState.h"

MainMenuState::MainMenuState() : State(AppState::MainMenu) {
    menu.addButton("Start", GameEvent::BeginGame);
    menu.addButton("Exit", GameEvent::QuitGame);

    addKeyBind(SDLK_ESCAPE, GameEvent::QuitGame);
    addKeyBind(SDLK_DOWN, GameEvent::MenuMoveDown);
    addKeyBind(SDLK_UP, GameEvent::MenuMoveUp);
    addKeyBind(SDLK_RETURN, GameEvent::MenuSelect);
    addKeyBind(SDLK_KP_ENTER, GameEvent::MenuSelect);
    subscribe(GameEvent::MenuMoveDown, [this]() {
        menu.menuMoveDown();
    });
    subscribe(GameEvent::MenuMoveUp, [this]() {
        menu.menuMoveUp();
    });
    subscribe(GameEvent::MenuSelect, [this]() {
        menu.pressSelectedButton();
    });
}

void MainMenuState::process() {
}

void MainMenuState::render(SDL_Surface* surface) const {
    menu.render(surface);
}