#include "testobjects.h"
#include "enums/gui_enums.h"

TestObject11::TestObject11():
    MovableObj()
{
    m_type = t_TestObject1;
    m_fcontroller = new FrameController(
                TextureProvider::getInstance()->getTexture(m_type));
}


TestObject22::TestObject22():
    ImmovableObj()
{
    m_type = t_StationBlock;
    m_fcontroller = new FrameController(
                TextureProvider::getInstance()->getTexture(m_type));
}



BackGround::BackGround():
    ImmovableObj()
{
    m_type = t_BACKGROUND;
    m_fcontroller = new FrameController(
                TextureProvider::getInstance()->getTexture(m_type), true);
    SDL_QueryTexture(m_fcontroller->getTexture(), NULL, NULL, &m_width, &m_height);
}

