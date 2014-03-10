#ifndef RENDER_H
#define RENDER_H

#include"SDL2/SDL.h"
#include "iostream"
#include "objectController/gobject.h"
#include "textureprovider.h"

class Render
{
public:
    Render(GOQueue *Queue);
    ~Render();
    bool init();
    void renderScreen();


private:
    SDL_Window * m_window;
    SDL_Renderer * m_rend;

    TextureProvider * m_textureProvider;

    void drawSurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend);

    GOQueue * m_queue;
};

#endif // RENDER_H
