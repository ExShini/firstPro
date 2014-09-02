#include "sf.h"
#include "enums/gui_enums.h"

SF::SF(Direction dir):
    MovableObj()
{
    m_type = t_SF;
    m_fcontroller = new FrameController(
                TextureProvider::getInstance()->getTexture(m_type), true, true, dir);
    m_width = 1;
    m_height = 1;
}
