#ifndef FRAMECONTROLLER_H
#define FRAMECONTROLLER_H
#include "SDL2/SDL.h"
#include "enums/objects.h"


class FrameController
{
public:
    FrameController(SDL_Texture* texture, bool fullTexture = false);
    void setTextureArea(int x, int y);
    SDL_Texture* getTexture();
    SDL_Rect getSrcRect();

protected:
    SDL_Texture* m_texture;
    bool m_fullTexture;

    SDL_Rect getFullRect();
    SDL_Rect getCurrRect();

    SDL_Rect m_pos;
};

#endif // FRAMECONTROLLER_H
