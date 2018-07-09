#include "Menu.h"

#include "GameEvent.h"
#include "StateManager.h"
#include "Button.h"

#include <SDL2/SDL_surface.h>

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

void Menu::render(SDL_Surface* surface) const {
    if (!transparent) {
        SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
    }
    for (const auto& button : buttons) {
        button->render(surface);
    }
}

void Menu::addButton(std::string text, GameEvent event) {
    buttons.emplace_back(std::make_unique<Button>(text, event));
    int buttonDist = SCREEN_HEIGHT / buttons.size();
    int curButtonDist = buttonDist/2;
    for (auto& button : buttons) {
        button->setCenter({SCREEN_WIDTH/2, curButtonDist});
        curButtonDist += buttonDist;
    }
    updateButtonSelection();
}

void Menu::updateButtonSelection() {
    for (int i = 0; i < buttons.size(); ++i) {
        buttons[i]->highlight = i == currentButton;
    }
}

void Menu::menuMoveDown() {
    currentButton = (currentButton + 1) % buttons.size();
    updateButtonSelection();
}

void Menu::menuMoveUp() {
    currentButton = (currentButton - 1) % buttons.size();
    updateButtonSelection();
}

void Menu::pressSelectedButton() {
    StateManager::get()->handleEvent(buttons[currentButton]->getEvent());
}

Menu::Menu(bool transparent) : transparent(transparent) {}
