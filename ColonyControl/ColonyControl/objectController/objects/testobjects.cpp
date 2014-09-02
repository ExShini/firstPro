#include "testobjects.h"
#include "enums/gui_enums.h"

TestObject11::TestObject11(Direction dir):
    MovableObj()
{
    m_type = t_TestObject1;
    m_fcontroller = new FrameController(
                TextureProvider::getInstance()->getTexture(m_type), true, true);
}


TestObject22::TestObject22():
    ImmovableObj()
{
    m_type = t_StationBlock;
    m_fcontroller = new FrameController(
                TextureProvider::getInstance()->getTexture(m_type), false, false);
}



BackGround::BackGround():
    ImmovableObj()
{
    m_type = t_BACKGROUND;
    m_fcontroller = new FrameController(
                TextureProvider::getInstance()->getTexture(m_type), false, false);
    SDL_QueryTexture(m_fcontroller->getTexture(), NULL, NULL, &m_width, &m_height);
}

