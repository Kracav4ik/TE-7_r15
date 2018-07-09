#include "InGameMenuState.h"

InGameMenuState::InGameMenuState() : MenuStateBase(AppState::InGameMenu) {
    menu.addButton("Continue", GameEvent::BackToGame);
    menu.addButton("Main menu", GameEvent::ExitToMainMenu);

    addKeyBind(SDLK_ESCAPE, GameEvent::BackToGame);
}

bool InGameMenuState::isTransparent() const {
    return true;
}

void InGameMenuState::render(SDL_Surface* surface) const {
    menu.render(surface);
}
