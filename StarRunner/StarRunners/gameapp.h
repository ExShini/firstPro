#ifndef GAMEAPP_H
#define GAMEAPP_H
#include "SDL2/SDL.h"

#include "render/render.h"
#include "eventController/eventcontroller.h"




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
    EventController * m_evController;


    // main handlers
    void initialize();
    void eventHandler();
    void gameProcessing();
    void rendring();
    void cleanup();


};

#endif // GAMEAPP_H
