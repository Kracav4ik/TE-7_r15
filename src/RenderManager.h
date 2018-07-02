#pragma once

#include "Singleton.h"

#include <vector>

struct SDL_Surface;
struct SDL_Window;

class Renderable;

class RenderManager: public Singleton<RenderManager> {
private:
    friend class Singleton<RenderManager>;
    RenderManager();
    std::vector<const Renderable*> renderables;

public:
    void render(SDL_Surface* surface, SDL_Window* window);
    void addRenderable(const Renderable* renderable);
};