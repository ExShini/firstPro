#include "iostream"

#include "mouseeventproc.h"


#ifdef WIN32
#include "../enums/gui_enums.h"
#else
#include "enums/gui_enums.h"
#endif

using namespace std;

MouseEventProc::MouseEventProc():
    m_mouseXCor(0),
    m_mouseYCor(0),
	m_pressedButton(false),
	m_releasedButton(false)
{
}


void MouseEventProc::processMouseMotionEvent(SDL_Event *event)
{
    SDL_MouseMotionEvent * ev = (SDL_MouseMotionEvent*)event;

    m_mouseXCor = ev->x;
    m_mouseYCor = ev->y;
}

void MouseEventProc::processMouseButtonEvent(SDL_Event *event)
{
	SDL_MouseButtonEvent * ev = (SDL_MouseButtonEvent*)(event);
	m_pressedButton |= (ev->which == SDL_PRESSED);
	m_releasedButton = (ev->which == SDL_RELEASED);

	if(m_pressedButton && m_releasedButton)
	{
		cout << "Mouse Button was pressed!" << endl;
	}
}