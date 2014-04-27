#include "movableobj.h"
#include "enums/objects.h"

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

    if (m_x >= MAP_WIDTH)
        m_x = MAP_WIDTH - 1;
    if (m_y >= MAP_HEIGHT)
        m_y = MAP_HEIGHT - 1;

    if (m_x < 0)
        m_x = 0;
    if (m_y < 0)
        m_y = 0;
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
