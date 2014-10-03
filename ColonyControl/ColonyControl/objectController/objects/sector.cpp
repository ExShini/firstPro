#include "sector.h"


#ifdef WIN32
#include "../../randomgen.h"
#else
#include "randomgen.h"
#endif

/*************************************
FUNC: Sector()
DESC: constructor
*************************************/
Sector::Sector()
{
    m_type = t_Sector;
    m_applicable = true;

    int fertilityDiff = LAVA_PLANET_DEFAULT_MAX_OF_FERTILITY - LAVA_PLANET_DEFAULT_MIN_OF_FERTILITY;
    m_fertility = LAVA_PLANET_DEFAULT_MIN_OF_FERTILITY + (RandomGen::getRand() % fertilityDiff);

    int mineralDiff = LAVA_PLANET_DEFAULT_MAX_OF_MINERAL - LAVA_PLANET_DEFAULT_MIN_OF_MINERAL;
    m_mineralWealth = LAVA_PLANET_DEFAULT_MIN_OF_MINERAL + (RandomGen::getRand() % mineralDiff);
}


/*************************************
FUNC: init()
DESC: prepare sector for drawing, set texture and graphic parameters
*************************************/
void Sector::init()
{
    m_fcontroller = new FrameController(
                TextureProvider::getInstance()->getTexture(m_type));

    short x = 1, y;
    y = RandomGen::getRand() % 4;

    if (m_fertility > LAVA_PLANET_DEFAULT_MAX_OF_FERTILITY)
        x = 0;

    if (m_mineralWealth > LAVA_PLANET_DEFAULT_MAX_OF_MINERAL)
        x = 2;

    m_fcontroller->setTextureArea(x, y);
    m_width = 1;
    m_height = 1;


}


bool Sector::itApplicable()
{
    return m_applicable;
}
