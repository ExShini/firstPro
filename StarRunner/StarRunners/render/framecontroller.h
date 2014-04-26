#ifndef FRAMECONTROLLER_H
#define FRAMECONTROLLER_H
#include "SDL2/SDL.h"
#include "enums/objects.h"


class FrameController
{
public:
    FrameController(SDL_Texture* texture);
    void setDirection(Direction dir) { m_direction = dir; }
    SDL_Texture* getTexture();
    SDL_Rect getSrcRect();

protected:
    SDL_Texture* m_texture;
    Direction m_direction;

};

#endif // FRAMECONTROLLER_H
