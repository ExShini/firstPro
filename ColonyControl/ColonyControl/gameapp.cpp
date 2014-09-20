#include "iostream"

#include "gameapp.h"
#include "SDL2/SDL.h"
#include "stdio.h"

using namespace std;

/*************************************
FUNC: GameApp()
DESC: constructor
*************************************/
GameApp::GameApp():
    m_gameStatus(0),
    m_render(0)
{
    m_gameStatus = 1;
    m_render = new Render();
    m_evController = new EventController(&m_gameStatus);
}

/*************************************
FUNC: ~GameApp()
DESC: destructor
*************************************/
GameApp::~GameApp()
{
    delete m_render;
    delete m_evController;
}

/*************************************
FUNC: startGame()
DESC: main game func - contain all game's main calls
*************************************/
void GameApp::startGame()
{
    cout << "Try initialize game" << endl;
    initialize();
    cout << "Start main Game cycle" << endl;
    while( m_gameStatus )
    {
        eventHandler();
        gameProcessing();
        rendring();
    }
    cleanup();
}


/*************************************
FUNC: initialize()
DESC: initialize and prepare all game's members
*************************************/
void GameApp::initialize()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        m_gameStatus = false;
    }

    m_gameStatus &= m_render->init();
}

/*************************************
FUNC: eventHandler()
DESC: handle all input events (mouse, keybord)
*************************************/
void GameApp::eventHandler()
{
    m_evController->processEvent();
}

/*************************************
FUNC: gameProcessing()
DESC: main game process handler
*************************************/
void GameApp::gameProcessing()
{
}

/*************************************
FUNC: rendring()
DESC: draw screan func
*************************************/
void GameApp::rendring()
{
    m_render->renderScreen();
}

/*************************************
FUNC: cleanup()
DESC: clean all resourses after game's end.
*************************************/
void GameApp::cleanup()
{
    SDL_Quit();
}
