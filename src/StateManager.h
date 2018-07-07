#pragma once

#include "Singleton.h"
#include "State.h"

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

    void pushState(const std::shared_ptr<State>& state);

    void popState();

    std::shared_ptr<State> getCurrentState();
    std::shared_ptr<State> getCurrentState() const;

    void handleEvent(GameEvent event) override;
};
