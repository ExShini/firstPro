#include "sector.h"

Sector::Sector():
    m_population(0),
    m_food(0),
    m_fertility(0),
    m_minerals(0),
    m_mineralWealth(0),
    m_production(0)
{
    m_type = t_Sector;
    m_fcontroller = new FrameController(
                TextureProvider::getInstance()->getTexture(m_type), false, false);
    m_width = 1;
    m_height = 1;
}
