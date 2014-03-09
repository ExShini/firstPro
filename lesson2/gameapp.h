#ifndef GAMEAPP_H
#define GAMEAPP_H
#include "enum.h"
#include "render.h"
#include "randomgen.h"
#include "aliveelement.h"


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
    RandomGen * m_randGen;

    AEQueue * m_queue;
    AliveElement * m_map[FIELD_WIDTH][FIELD_HEIGHT];

    // main handlers
    void initialize();
    void eventHandler();
    void gameProcessing();
    void rendring();
    void cleanup();


    // game-processing funcs and members:
    void createLive(short x, short y);
    void checkEnv(AliveElement* el);
    bool enoughWaiting();


};

#endif // GAMEAPP_H
