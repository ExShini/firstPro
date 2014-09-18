#include "keyboardeventproc.h"

KeyboardEventProc::KeyboardEventProc(short *gameStatus):
    m_toRight(false),
    m_toLeft(false),
    m_toUp(false),
    m_toDown(false)
{
    m_objContr = ObjectController::getInstance();
    m_gameStatus = gameStatus;
}

void KeyboardEventProc::processEvent(SDL_Event *event)
{

    SDL_KeyboardEvent * ev = (SDL_KeyboardEvent*)event;

    //ev->state can be 0 (SDL_RELEASED) or 1 (SDL_PRESSED)
    bool pressed = (bool)ev->state;

    switch (ev->keysym.scancode)
    {
    case SDL_SCANCODE_RIGHT:
    case SDL_SCANCODE_D:
        m_toRight = pressed;
        break;
    case SDL_SCANCODE_LEFT:
    case SDL_SCANCODE_A:
        m_toLeft = pressed;
        break;
    case SDL_SCANCODE_DOWN:
    case SDL_SCANCODE_S:
        m_toDown = pressed;
        break;
    case SDL_SCANCODE_UP:
    case SDL_SCANCODE_W:
        m_toUp = pressed;
        break;
    case SDL_SCANCODE_ESCAPE:
        *m_gameStatus = false;
        break;
    default:
        break;
    }



}
