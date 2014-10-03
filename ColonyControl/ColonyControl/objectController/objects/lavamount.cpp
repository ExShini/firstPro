#include "lavamount.h"

#ifdef WIN32
#include "../../randomgen.h"
#else
#include "randomgen.h"
#endif

LavaMount::LavaMount()
{
    m_type = t_LavaMount;
    m_applicable = false;

    m_fcontroller = new FrameController(
                TextureProvider::getInstance()->getTexture(m_type));

    short x = 1, y = 0;
    //y = RandomGen::getRand() % 4;

    m_fcontroller->setTextureArea(x, y);
    m_width = 1;
    m_height = 1;
}
