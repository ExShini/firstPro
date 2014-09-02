#ifndef FRAMECONTROLLER_H
#define FRAMECONTROLLER_H
#include "SDL2/SDL.h"
#include "enums/objects.h"


class FrameController
{
public:
    FrameController(SDL_Texture* texture, bool rotation, bool mooveble, Direction dir = DOWN);
    void setDirection(Direction dir);
    SDL_Texture* getTexture();
    SDL_Rect getSrcRect();

protected:
    SDL_Texture* m_texture;
    Direction m_direction;

    bool m_rotation;
    bool m_moveble;

    SDL_Rect getFullRect();
    SDL_Rect getCurrRect();


};

#endif // FRAMECONTROLLER_H
