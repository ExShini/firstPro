#ifndef RENDER_H
#define RENDER_H

#include"SDL2/SDL.h"
#include "iostream"
#include "aliveelement.h"

class Render
{
public:
    Render(AEQueue * Queue);
    ~Render();
    bool init();
    void renderScreen();


private:
    SDL_Window * m_window;
    SDL_Renderer * m_rend;

    SDL_Texture* m_back;
    SDL_Texture * m_aliveTexture;

    bool loadBackGround();
    void drawSurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend);
    SDL_Texture * loadImage(std::string file);

    AEQueue * m_queue;
};

#endif // RENDER_H
