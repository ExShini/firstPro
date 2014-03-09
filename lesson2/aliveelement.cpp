#include "aliveelement.h"
#include "string.h"

AliveElement::AliveElement(short x, short y ):
    m_previous(0),
    m_next(0)
{
    m_x = x;
    m_y = y;

    m_countEmpty = m_countLive = 0;
    m_ears = 2;

    memset(m_empty, 0, sizeof(point) * 4);
    memset(m_liveAround, 0, sizeof(point) * 4);
}

AliveElement::~AliveElement()
{

}

bool AliveElement::Die()
{
    m_ears--;

    if (!m_ears)
    {

        // remove this element from queue
        if (m_previous)
        {
            m_previous->setNextEl(m_next);
        }
        if (m_next)
        {
            m_next->setPreviousEl(m_previous);
        }
        // just.. kill me..
        delete this;
        return true;
    }
    else
    {
        return false;
    }
}
