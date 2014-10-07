#ifndef UNIT_H
#define UNIT_H

#ifdef WIN32
#include "../render/framecontroller.h"
#else
#include "render/framecontroller.h"
#endif


class Unit
{
public:
    Unit();
    virtual ~Unit();
    virtual void process() = 0;
    int getX() { return m_x; }
    int getY() { return m_y; }
    int getAngle() { return m_alpha; }
    bool isActive() { return m_active; }
    FrameController* getFrameController() { return m_fcontroller; }

protected:
    int m_x, m_y;
    int m_alpha;
    bool m_active;
    FrameController* m_fcontroller;
};



struct Vec
{
    int X;
    int Y;
};

#endif // UNIT_H
