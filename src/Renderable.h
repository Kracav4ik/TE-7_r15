#pragma once

struct SDL_Surface;

class Renderable {
public:
    virtual void render(SDL_Surface* pSurface) const = 0;

protected:
    ~Renderable() = default;
};
