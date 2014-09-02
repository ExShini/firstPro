#include "floor.h"
#include "enums/gui_enums.h"

Floor::Floor():
    ImmovableObj()
{
    m_type = t_Floor;
    m_fcontroller = new FrameController(
                TextureProvider::getInstance()->getTexture(m_type), true, false);
    m_width = 1;
    m_height = 1;
}
