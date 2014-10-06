#ifndef GAMEAPP_H
#define GAMEAPP_H

#ifdef WIN32
#include"SDL.h"
#else
#include"SDL2/SDL.h"
#endif

#include "render/render.h"
#include "eventController/eventcontroller.h"
#include "gameProcessor/gameprocessor.h"
#include "gameProcessor/unitcontroller.h"



class GameApp
{
public:
    GameApp();
    void StartGame();
    ~GameApp();

private:

    // memebers:
    short m_gameStatus;
    Render * m_render;
    EventController * m_evController;
    GameProcessor * m_gameProcessor;
    UnitController* m_unitController;


    // main handlers
    void initialize();
    void eventHandler();
    void gameProcessing();
    void rendring();
    void cleanup();


};

#endif // GAMEAPP_H
