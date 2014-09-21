#include "settlement.h"

Settlement::Settlement()
{
    m_type = t_HumanSettlers;
    m_fcontroller = new FrameController(
                TextureProvider::getInstance()->getTexture(m_type));

    m_width = 1;
    m_height = 1;
}
