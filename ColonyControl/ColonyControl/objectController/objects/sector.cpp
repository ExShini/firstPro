#include "sector.h"
#include "randomgen.h"

/*************************************
FUNC: Sector()
DESC: constructor
*************************************/
Sector::Sector()
{
    m_type = t_Sector;

    m_fertility = 1500; //test
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

    m_fcontroller->setTextureArea(x, y);
    m_width = 1;
    m_height = 1;
}
