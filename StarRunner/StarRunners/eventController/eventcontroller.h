#ifndef EVENTCONTROLLER_H
#define EVENTCONTROLLER_H
#include "SDL2/SDL.h"
#include "keyboardeventproc.h"

class EventController
{
public:
    EventController(short *gameStatus);
    void processEvent();

protected:
    short * m_gameStatus;
    KeyboardEventProc * m_keyProc;

};

#endif // EVENTCONTROLLER_H
