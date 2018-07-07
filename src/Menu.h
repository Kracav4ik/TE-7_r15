#pragma once

#include "Renderable.h"
#include "Button.h"
#include "GameEvent.h"

#include <vector>
#include <memory>
#include <string>

class Menu: public Renderable {
private:
    int currentButton = 0;
    std::vector<std::unique_ptr<Button>> buttons;

    void updateButtonSelection();

public:
    void render(SDL_Surface* surface) const override;
    void addButton(std::string text, GameEvent event);
    void menuMoveDown();
    void menuMoveUp();
    void pressSelectedButton();
};
