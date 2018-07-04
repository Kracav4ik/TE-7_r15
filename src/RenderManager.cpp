#include "RenderManager.h"

#include "Renderable.h"
#include "State.h"

#include <SDL2/SDL_video.h>

RenderManager::RenderManager(State& state):state(state) {}

void RenderManager::render(SDL_Surface* surface, SDL_Window* window) {
    if (state.isGameState()) {
        SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 0x00, 0x00, 0x00));
        for (const auto& renderable : renderables) {
            renderable->render(surface);
        }
    } else {
        SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));
    }
    SDL_UpdateWindowSurface(window);
}

void RenderManager::addRenderable(std::shared_ptr<Renderable> renderable) {
    renderables.push_back(renderable);
}
