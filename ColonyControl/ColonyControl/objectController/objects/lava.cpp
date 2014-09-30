#include "lava.h"
#include "randomgen.h"

Lava::Lava()
{
    m_type = t_Lava;
    m_applicable = false;

    m_fcontroller = new FrameController(
                TextureProvider::getInstance()->getTexture(m_type));

    short x = 0, y = 0;
    y = RandomGen::getRand() % 2;

    m_fcontroller->setTextureArea(x, y);
    m_width = 1;
    m_height = 1;
}
