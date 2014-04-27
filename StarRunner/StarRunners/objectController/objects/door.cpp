#include "door.h"
#include "enums/gui_enums.h"

Door::Door():
    ImmovableObj()
{
    m_type = t_Door;
    m_fcontroller = new FrameController(
                TextureProvider::getInstance()->getTexture(m_type), true, false);
    m_width = 1;
    m_height = 1;
}
