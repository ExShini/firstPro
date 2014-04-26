#include "gobject.h"

GObject::GObject(ObjectsType type):
    m_x(0),
    m_y(0),
    m_width(0),
    m_height(0),
    m_fcontroller(NULL),
    m_type(type)
{
    m_fcontroller = new FrameController(
                TextureProvider::getInstance()->getTexture(m_type));
}

GObject::~GObject()
{
    if (m_fcontroller != NULL)
        delete m_fcontroller;
}
