#pragma once

#include "Singleton.h"
#include "states/State.h"

#include <stack>
#include <memory>

class StateManager: public Singleton<StateManager>, public State {
private:
    friend class Singleton<StateManager>;
    StateManager();

    std::stack<std::shared_ptr<State>> states;
    bool quit = false;

public:
    bool isQuit() const;

    void process() override;

    void render(SDL_Surface* surface) const override;

    template<typename StateClass>
    void pushState() {
        pushState(std::static_pointer_cast<State>(std::make_shared<StateClass>()));
    }
    void pushState(const std::shared_ptr<State>& state);

    void popState();

    bool handleKey(SDL_Keycode key) override;

    std::shared_ptr<State> getCurrentState();
    std::shared_ptr<State> getCurrentState() const;

    void handleEvent(GameEvent event) override;
};
