#include "gobject.h"

GObject::GObject():
    m_x(0),
    m_y(0),
    m_width(0),
    m_height(0),
    m_fcontroller(NULL),
    m_type(NULLOBJECT)
{
}

GObject::~GObject()
{
    if (m_fcontroller != NULL)
        delete m_fcontroller;
}
