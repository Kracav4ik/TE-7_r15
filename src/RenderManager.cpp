#include "RenderManager.h"

#include "Renderable.h"

#include <SDL2/SDL_video.h>

RenderManager::RenderManager() = default;

void RenderManager::render(SDL_Surface* surface, SDL_Window* window) {
    SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 0x00, 0x00, 0x00));
    for (auto renderable : renderables) {
        renderable->render(surface);
    }
    SDL_UpdateWindowSurface(window);
}

void RenderManager::addRenderable(const Renderable* renderable) {
    renderables.push_back(renderable);
}
