#ifndef EVENTCONTROLLER_H
#define EVENTCONTROLLER_H
#include "SDL2/SDL.h"
#include "keyboardeventproc.h"
#include "mouseeventproc.h"

class EventController
{
public:
    EventController(short *gameStatus);
    void processEvent();

protected:
    void HandleCameraMoving();

    short * m_gameStatus;
    KeyboardEventProc * m_keyProc;
    MouseEventProc * m_mouseProc;
    ObjectController * m_objContr;

};

#endif // EVENTCONTROLLER_H
