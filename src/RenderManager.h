#pragma once

#include "Singleton.h"

#include <vector>
#include <memory>

struct SDL_Surface;
struct SDL_Window;

class Renderable;

class RenderManager: public Singleton<RenderManager> {
private:
    friend class Singleton<RenderManager>;
    explicit RenderManager(State& state);
    std::vector<std::shared_ptr<Renderable>> renderables;
    State& state;

public:
    void render(SDL_Surface* surface, SDL_Window* window);
    void addRenderable(std::shared_ptr<Renderable> renderable);
};