#include "eventcontroller.h"
#include "iostream"
#include "enums/event_handling_enum.h"

using namespace std;

EventController::EventController(short *gameStatus)
{
    m_gameStatus = gameStatus;
    m_keyProc = new KeyboardEventProc(m_gameStatus);
    m_mouseProc = new MouseEventProc();
    m_objContr = ObjectController::getInstance();
}

void EventController::processEvent()
{
    SDL_Event Event;
    while(SDL_PollEvent(&Event))
    {
        switch (Event.type)
        {
        case SDL_QUIT:
            *m_gameStatus = 0;
            break;
        case SDL_KEYDOWN:
        case SDL_KEYUP:
            m_keyProc->processEvent(&Event);
            break;
        case SDL_MOUSEMOTION:
            m_mouseProc->processEvent(&Event);
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

    HandleMoving();
}



void EventController::HandleMoving()
{
    //check - should we move camera?
    if (m_mouseProc->m_mouseXCor < W_MIN_SCKROL_AREA || m_keyProc->m_toLeft)
    {
        m_objContr->getPlayer()->move(-1,0);
    }

    if (m_mouseProc->m_mouseXCor > W_MAX_SCKROL_AREA || m_keyProc->m_toRight)
    {
        m_objContr->getPlayer()->move(1,0);
    }

    if (m_mouseProc->m_mouseYCor > H_MAX_SCKROL_AREA || m_keyProc->m_toDown)
    {
        m_objContr->getPlayer()->move(0,1);
    }

    if (m_mouseProc->m_mouseYCor < H_MIN_SCKROL_AREA || m_keyProc->m_toUp)
    {
        m_objContr->getPlayer()->move(0,-1);
    }
}
