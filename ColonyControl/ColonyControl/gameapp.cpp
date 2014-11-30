#include "gameapp.h"

#include "iostream"
#include "stdio.h"

#include "TimeManager/timeguard.h"


#ifdef WIN32
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

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
    m_gameProcessor = GameProcessor::getInstance();
    m_unitController = UnitController::getInstance();
    m_uiController = UIController::getInstance();
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
FUNC: StartGame()
DESC: main game func - contain all game's main calls
*************************************/
void GameApp::StartGame()
{
    cout << "Try initialize game" << endl;
    initialize();
    TimeGuard* timeGuard = TimeGuard::getInstance();
    timeGuard->Start();
    cout << "iter main Game cycle" << endl;
    while( m_gameStatus )
    {
        timeGuard->checkTime();
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

    m_unitController->init();
    m_gameProcessor->init();
    m_gameStatus &= m_render->init();
    m_uiController->Init();
    m_evController->Init();


    m_gameProcessor->addNewPlayer(10, 10, Human);

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
    m_gameProcessor->process();
    m_unitController->process();
    m_uiController->process();
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
