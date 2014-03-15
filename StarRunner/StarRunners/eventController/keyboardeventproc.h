#ifndef KEYBOARDEVENTPROC_H
#define KEYBOARDEVENTPROC_H
#include "SDL2/SDL.h"
#include "objectController/objectcontroller.h"

class KeyboardEventProc
{
public:
    KeyboardEventProc(short * gameStatus);
    void processEvent(SDL_Event* event);

protected:
    ObjectController * m_objContr;
    short * m_gameStatus;
};

#endif // KEYBOARDEVENTPROC_H
