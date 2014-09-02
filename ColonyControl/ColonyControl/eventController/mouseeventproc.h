#ifndef MOUSEEVENTPROC_H
#define MOUSEEVENTPROC_H
#include "SDL2/SDL.h"
#include "objectController/objectcontroller.h"

class MouseEventProc
{
public:
    MouseEventProc();
    void processEvent(SDL_Event* event);
    int m_mouseXCor, m_mouseYCor;

protected:


};

#endif // MOUSEEVENTPROC_H
