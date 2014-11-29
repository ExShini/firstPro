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
    void Init();

protected:
    void HandleCameraMoving();
    void setTargetToSector();

    short * m_gameStatus;
    KeyboardEventProc * m_keyProc;
    MouseEventProc * m_mouseProc;
    ObjectController * m_objContr;


    CameraObject* m_camera;
    TargetObject* m_target;
};

#endif // EVENTCONTROLLER_H
