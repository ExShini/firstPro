#ifndef TEXTPROVIDER_H
#define TEXTPROVIDER_H
#include "iostream"
#include "string"

#ifdef WIN32
#include"SDL.h"
#include "SDL_ttf.h"
#else
#include"SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#endif

using namespace std;

class TextProvider
{
public:
    static TextProvider * getInstance();
    void setRenderer(SDL_Renderer * renderer);
    SDL_Texture * getTextuteByText(string & text, TTF_Font* font, SDL_Color color);

    bool Init();

protected:
    TextProvider();
    static TextProvider* m_instance;

    SDL_Renderer * m_renderer;
};

#endif // TEXTPROVIDER_H
