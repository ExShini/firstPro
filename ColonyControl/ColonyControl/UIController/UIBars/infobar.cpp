#include "iostream"

#include "infobar.h"
#include "render/textureprovider.h"

using namespace std;

InfoBar::InfoBar()
    :UIBar()
{
    m_type = t_HumanInfoBar;
    m_fcontroller = new FrameController(
                TextureProvider::getInstance()->getTexture(m_type), true);

    m_x = 362;
    m_y = 520;

    m_width = 300;
    m_height = 120;
}
