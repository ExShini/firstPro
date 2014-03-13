#ifndef RENDER_H
#define RENDER_H

#include"SDL2/SDL.h"
#include "iostream"
#include "objectController/objectcontroller.h"
//#include "objectController/gobject.h"
//#include "textureprovider.h"


class Render
{
public:
    Render();
    ~Render();
    bool init();
    void renderScreen();


private:
    SDL_Window * m_window;
    SDL_Renderer * m_rend;

    TextureProvider * m_textureProvider;

    void drawSurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend);

    ObjectController* m_objController;
    list<GObject*>* m_olist;
};

#endif // RENDER_H
