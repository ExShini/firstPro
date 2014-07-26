#include "keyboardeventproc.h"

KeyboardEventProc::KeyboardEventProc(short *gameStatus)
{
    m_objContr = ObjectController::getInstance();
    m_gameStatus = gameStatus;
}

void KeyboardEventProc::processEvent(SDL_Event *event)
{
    SDL_KeyboardEvent * ev = (SDL_KeyboardEvent*)event;
    switch (ev->keysym.scancode)
    {
    case SDL_SCANCODE_RIGHT:
    case SDL_SCANCODE_D:
        m_objContr->getPlayer()->move(1,0);
        break;
    case SDL_SCANCODE_LEFT:
    case SDL_SCANCODE_A:
        m_objContr->getPlayer()->move(-1,0);
        break;
    case SDL_SCANCODE_DOWN:
    case SDL_SCANCODE_S:
        m_objContr->getPlayer()->move(0,1);
        break;
    case SDL_SCANCODE_UP:
    case SDL_SCANCODE_W:
        m_objContr->getPlayer()->move(0,-1);
        break;
    case SDL_SCANCODE_ESCAPE:
        *m_gameStatus = false;
        break;
    default:
        break;
    }



}
