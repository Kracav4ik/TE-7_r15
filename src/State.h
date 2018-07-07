#pragma once

#include "GameObject.h"
#include "Renderable.h"

#include <functional>
#include <map>

enum class GameEvent;

enum class AppState {
    Menu,
    Game,
    NoState, // special state for StateManager which is a State too
};

class State: public Renderable, public GameObject  {
public:
    using CallbackType = std::function<void()>;

    explicit State(AppState currentState);

    void process() override;

    void render(SDL_Surface* surface) const override;

    bool isGameState() const;

    virtual void handleEvent(GameEvent event);

    State(State&&) = delete;
    State(const State&) = delete;

private:
    AppState currentState;
    std::multimap<GameEvent, CallbackType> callbacks;

protected:
    void subscribe(GameEvent event, CallbackType callback);

};
