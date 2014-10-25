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
    Unit(int playerID);
    virtual ~Unit();
    virtual void process() = 0;
    int getX() { return m_x; }
    int getY() { return m_y; }
    int getAngle() { return m_alpha; }

    void setX(int x) { m_x = x; }
    void setY(int y) { m_y = y; }

    bool isActive() { return m_active; }
    void finishActive() { m_active = false; }
    FrameController* getFrameController() { return m_fcontroller; }
    int getPlayerID() { return m_playerID; }

protected:
    int m_x, m_y;
    int m_alpha;
    bool m_active;
    FrameController* m_fcontroller;
    int m_playerID;
};



struct Vec
{
    int X;
    int Y;
};

#endif // UNIT_H
