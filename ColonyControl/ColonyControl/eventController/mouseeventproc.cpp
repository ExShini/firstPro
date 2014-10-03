#include "mouseeventproc.h"


#ifdef WIN32
#include "../enums/gui_enums.h"
#else
#include "enums/gui_enums.h"
#endif

MouseEventProc::MouseEventProc():
    m_mouseXCor(0),
    m_mouseYCor(0)
{
}


void MouseEventProc::processEvent(SDL_Event *event)
{
    SDL_MouseMotionEvent * ev = (SDL_MouseMotionEvent*)event;

    m_mouseXCor = ev->x;
    m_mouseYCor = ev->y;
}
