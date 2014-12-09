#ifndef MOUSEEVENTPROC_H
#define MOUSEEVENTPROC_H

#ifdef WIN32
#include"SDL.h"
#include "../objectController/objectcontroller.h"
#else
#include"SDL2/SDL.h"
#include "objectController/objectcontroller.h"
#endif



class MouseEventProc
{
public:
    MouseEventProc();
    void processMouseMotionEvent(SDL_Event* event);
	void processMouseButtonEvent(SDL_Event* event);

    int m_mouseXCor, m_mouseYCor;

protected:
	bool m_pressedButton;
	bool m_releasedButton;

};

#endif // MOUSEEVENTPROC_H
