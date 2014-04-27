#include "wall.h"
#include "enums/gui_enums.h"

wall::wall():
    ImmovableObj()
{
    m_type = t_Wall;
    m_fcontroller = new FrameController(
                TextureProvider::getInstance()->getTexture(m_type), true, false);
    m_width = 1;
    m_height = 1;
}
