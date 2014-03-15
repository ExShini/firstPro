#include "eventcontroller.h"
#include "iostream"

using namespace std;

EventController::EventController(short *gameStatus)
{
    m_gameStatus = gameStatus;
    m_keyProc = new KeyboardEventProc(m_gameStatus);
}

void EventController::processEvent()
{
    SDL_Event Event;
    while(SDL_PollEvent(&Event))
    {
        switch (Event.type) {
        case SDL_QUIT:
            *m_gameStatus = 0;
            break;
        case SDL_KEYDOWN:
        case SDL_KEYUP:
            m_keyProc->processEvent(&Event);
            break;
        default:
            //cout << "unused event ";
            break;
        }


        if(Event.type == SDL_QUIT)
        {
            m_gameStatus = 0;
        }
    }
}
