#include "medbox.h"
#include "enums/gui_enums.h"

MedBox::MedBox(Direction dir):
    ImmovableObj()
{
    m_type = t_MedBox;
    m_fcontroller = new FrameController(
                TextureProvider::getInstance()->getTexture(m_type), true, false, dir);
    m_width = 1;
    m_height = 1;
}
