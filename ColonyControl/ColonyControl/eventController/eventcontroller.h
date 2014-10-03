#ifndef EVENTCONTROLLER_H
#define EVENTCONTROLLER_H

#ifdef WIN32
#include"SDL.h"
#include "../ColonyControlWin/stdafx.h"
#else
#include"SDL2/SDL.h"
#endif

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
