#pragma once

#include "Singleton.h"

#include <vector>
#include <memory>

struct SDL_Surface;
struct SDL_Window;
struct SDL_Point;
struct SDL_Rect;

class Renderable;

SDL_Rect operator+(const SDL_Rect& r, const SDL_Point& p);

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