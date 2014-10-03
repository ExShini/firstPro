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

    m_fertility = 1500; //test
    m_applicable = true;
}


/*************************************
FUNC: init()
DESC: prepare sector for drawing, set texture and graphic parameters
*************************************/
void Sector::init()
{
    m_fcontroller = new FrameController(
                TextureProvider::getInstance()->getTexture(m_type));

    short x = 0, y;
    y = RandomGen::getRand() % 4;

    m_fcontroller->setTextureArea(x, y);
    m_width = 1;
    m_height = 1;
}


bool Sector::itApplicable()
{
    return m_applicable;
}
