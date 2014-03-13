#ifndef GAMEAPP_H
#define GAMEAPP_H
#include "render/render.h"
#include "SDL2/SDL.h"


class GameApp
{
public:
    GameApp();
    void startGame();
    ~GameApp();

private:

    // memebers:
    short m_gameStatus;
    Render * m_render;

    // main handlers
    void initialize();
    void eventHandler();
    void gameProcessing();
    void rendring();
    void cleanup();


};

#endif // GAMEAPP_H
