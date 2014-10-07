#include "unit.h"

Unit::Unit()
{
}

Unit::~Unit()
{
    if (m_fcontroller != NULL)
    {
        delete m_fcontroller;
        m_fcontroller = NULL;
    }
}
