#ifndef FRAMECONTROLLER_H
#define FRAMECONTROLLER_H

#ifdef WIN32
#include"SDL.h"
#include "../ColonyControlWin/stdafx.h"
#include "../enums/objects.h"
#else
#include"SDL2/SDL.h"
#include "enums/objects.h"
#endif



class FrameController
{
public:
    FrameController(bool fullTexture = false);
    FrameController(SDL_Texture* texture, bool fullTexture = false);
    void setNewTexture(SDL_Texture* texture, bool fullTexture = false);
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
