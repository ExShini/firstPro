#include "gameapp.h"
#include "enum.h"
#include "SDL2/SDL.h"
#include "stdio.h"

using namespace std;

/*************************************
FUNC: GameApp()
DESC: constructor
*************************************/
GameApp::GameApp():
    m_gameStatus(0),
    m_render(0),
    m_randGen(0),
    m_queue(0)
{
    m_queue = (AEQueue*) calloc(1, sizeof(AEQueue));
    m_render = new Render(m_queue);
    m_randGen = new RandomGen();

    for (int i = 0; i < FIELD_WIDTH; i++)
    {
        for (int j = 0; j < FIELD_HEIGHT; j++)
        {
            m_map[i][j] = NULL;
        }
    }
}

/*************************************
FUNC: ~GameApp()
DESC: destructor
*************************************/
GameApp::~GameApp()
{
    delete m_render;
    delete m_randGen;
    delete[] m_map;

    free(m_queue);
}

/*************************************
FUNC: startGame()
DESC: main game func - contain all game's main calls
*************************************/
void GameApp::startGame()
{
    initialize();
    while( m_gameStatus & ACTIVE_GAME )
    {
        eventHandler();
        gameProcessing();
        rendring();
        SDL_Delay(70);
    }
    cleanup();
}


/*************************************
FUNC: initialize()
DESC: initialize and prepare all game's members
*************************************/
void GameApp::initialize()
{
    bool status = true;
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    {
        status = false;
    }

    status &= m_render->init();

    if (status)
    {
        m_gameStatus |= ACTIVE_GAME;
    }

    //init start field
    short rand;
    for (int x = 0; x < FIELD_WIDTH; x ++)
    {
        for (int y = 0; y < FIELD_HEIGHT; y++)
        {
            rand = RandomGen::getRand();
            if (rand <= BORDER_OF_LIVE)
            {
                createLive( x, y );
            }
        }
    }
}

/*************************************
FUNC: eventHandler()
DESC: handle all input events (mouse, keybord)
*************************************/
void GameApp::eventHandler()
{
    SDL_Event Event;
    while(SDL_PollEvent(&Event))
    {
        if(Event.type == SDL_KEYDOWN)
        {
            m_gameStatus = 0;
        }
    }
}

/*************************************
FUNC: gameProcessing()
DESC: main game process handler
*************************************/
void GameApp::gameProcessing()
{
    AliveElement * el = m_queue->m_head;
    AliveElement * tail = m_queue->m_tail;
    bool foundEnd = false;
    short numEmpty;
    short x, y;

    short remX;
    short remY;
    bool remFirst;

    // if queue have not elements - we should not process it
    if (el == NULL)
    {
        foundEnd = true;
    }

    // process all element from queue

    while ( !foundEnd )
    {
        // if we found the end of queue
        if (el == tail)
        {
            foundEnd = true;
        }

        numEmpty = 0;
        AliveElement * currEl = el;
        checkEnv(el);

        if (el->getNumAlive())
        {
            numEmpty = el->getNumEmpty();
            if (numEmpty)
            {
                if (RandomGen::getRand() < BIRTH_RATE)
                {
                    short posit = RandomGen::getRand() % numEmpty;
                    point * currPoint = el->getPEmpty();
                    x = currPoint[posit].m_x;
                    y = currPoint[posit].m_y;

                    createLive( x, y );
                }
            }
        }

        el = el->getNextEl();
        //remove element from map and kill him! uhaha! ^_^

        remX = currEl->getX();
        remY = currEl->getY();
        remFirst = currEl == m_queue->m_head;

        if (currEl->Die())
        {
            m_map[remX][remY] = currEl = NULL;
            if (remFirst)
            {
                m_queue->m_head = el;
            }
        }
    }
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

/*************************************
FUNC: createLive()
DESC: create new Live in x and y coordinats.
*************************************/
void GameApp::createLive(short x, short y)
{
    AliveElement * el = new AliveElement( x, y );

    // add element in queue
    if (m_queue->m_head == NULL)
    {
        m_queue->m_head = el;
    }
    else
    {
        el->setPreviousEl(m_queue->m_tail);
        m_queue->m_tail->setNextEl(el);
    }
    m_queue->m_tail = el;

    //add element in map
    m_map[ x ][ y ] = el;
}

/*************************************
FUNC: checkEnv()
DESC: check envirement of this element and try find over live and empty plase around.
*************************************/
void GameApp::checkEnv(AliveElement *el)
{
    AliveElement * checked;
    short alive = 0, empty = 0;
    point * aliveAround;
    point * emptyAround;

    aliveAround = el->getPAlive();
    emptyAround = el->getPEmpty();

    //check left side
    if (el->getX() - 1 >= 0)
    {
        checked = m_map [el->getX() - 1][el->getY()];
        if (checked)
        {
            aliveAround[alive].m_x = el->getX() - 1;
            aliveAround[alive].m_y = el->getY();
            alive++;
        }
        else
        {
            emptyAround[empty].m_x = el->getX() - 1;
            emptyAround[empty].m_y = el->getY();
            empty++;
        }
    }

    //check right side
    if (el->getX() + 1 < FIELD_WIDTH)
    {
        checked = m_map [el->getX() + 1][el->getY()];
        if (checked)
        {
            aliveAround[alive].m_x = el->getX() + 1;
            aliveAround[alive].m_y = el->getY();
            alive++;
        }
        else
        {
            emptyAround[empty].m_x = el->getX() + 1;
            emptyAround[empty].m_y = el->getY();
            empty++;
        }
    }

    //check top side
    if (el->getY() - 1 >= 0)
    {
        checked = m_map [el->getX()][el->getY() - 1];
        if (checked)
        {
            aliveAround[alive].m_x = el->getX();
            aliveAround[alive].m_y = el->getY() - 1;
            alive++;
        }
        else
        {
            emptyAround[empty].m_x = el->getX();
            emptyAround[empty].m_y = el->getY() - 1;
            empty++;
        }
    }

    //check lower side
    if (el->getY() + 1 < FIELD_HEIGHT)
    {
        checked = m_map [el->getX()][el->getY() + 1];
        if (checked)
        {
            aliveAround[alive].m_x = el->getX();
            aliveAround[alive].m_y = el->getY() + 1;
            alive++;
        }
        else
        {
            emptyAround[empty].m_x = el->getX();
            emptyAround[empty].m_y = el->getY() + 1;
            empty++;
        }
    }

    //set new value for current element
    el->setNumAlive(alive);
    el->setNumEmpty(empty);
}


bool GameApp::enoughWaiting()
{
    //TODO
}
