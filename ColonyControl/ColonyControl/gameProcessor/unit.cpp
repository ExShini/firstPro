#include "unit.h"

Unit::Unit(int playerID)
{
    m_playerID = playerID;
}

Unit::~Unit()
{
    if (m_fcontroller != NULL)
    {
        delete m_fcontroller;
        m_fcontroller = NULL;
    }
}
