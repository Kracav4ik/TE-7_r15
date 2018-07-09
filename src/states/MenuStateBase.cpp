#include "MenuStateBase.h"

#include "GameEvent.h"

MenuStateBase::MenuStateBase(AppState currentState) : State(currentState) {
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
