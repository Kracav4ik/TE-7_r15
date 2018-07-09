#pragma once

#include "State.h"
#include "Menu.h"

class MenuStateBase : public State {
protected:
    Menu menu;

    explicit MenuStateBase(AppState currentState);
};
