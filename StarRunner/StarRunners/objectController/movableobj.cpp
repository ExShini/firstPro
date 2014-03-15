#include "movableobj.h"

/************************************************************/
// MovableObj
/************************************************************/
MovableObj::MovableObj():
    GObject()
{}

void MovableObj::move(int xDiff, int yDiff)
{
    m_x += xDiff;
    m_y += yDiff;
}


/************************************************************/
// ImmovableObj
/************************************************************/
ImmovableObj::ImmovableObj():
    GObject()
{}

void ImmovableObj::move(int xDiff, int yDiff)
{
    m_x += xDiff;
    m_y += yDiff;
}
