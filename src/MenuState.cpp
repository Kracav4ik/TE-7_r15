#include "MenuState.h"

MenuState::MenuState() : State(AppState::Menu) {}

void MenuState::process() {
}

void MenuState::render(SDL_Surface* surface) const {
    menu.render(surface);
}
