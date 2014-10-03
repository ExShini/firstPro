#ifndef KEYBOARDEVENTPROC_H
#define KEYBOARDEVENTPROC_H

#ifdef WIN32
#include"SDL.h"
#include "../objectController/objectcontroller.h"
#else
#include"SDL2/SDL.h"
#include "objectController/objectcontroller.h"
#endif



class KeyboardEventProc
{
public:
    KeyboardEventProc(short * gameStatus);
    void processEvent(SDL_Event* event);

    bool m_toRight, m_toLeft, m_toUp, m_toDown;


protected:
    ObjectController * m_objContr;
    short * m_gameStatus;
};

#endif // KEYBOARDEVENTPROC_H
