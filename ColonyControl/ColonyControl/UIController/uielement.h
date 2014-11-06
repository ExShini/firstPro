#ifndef UIELEMENT_H
#define UIELEMENT_H

#ifdef WIN32
#include "../render/framecontroller.h"
#else
#include "render/framecontroller.h"
#endif


class UIElement
{
public:
    int getX();
    int getY();
    FrameController* getFController();

    void setX(int x);
    void setY(int y);

protected:
    UIElement();

    int m_x, m_y;
    FrameController* m_frController;
};

#endif // UIELEMENT_H
