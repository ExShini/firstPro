#include "testobjects.h"
#include "enums/gui_enums.h"

TestObject11::TestObject11():
    MovableObj()
{
    m_type = t_TestObject1;
    m_texture = TextureProvider::getInstance()->getTexture(m_type);
    SDL_QueryTexture(m_texture, NULL, NULL, &m_width, &m_height);
    m_width = m_width DIVIDE_FS;
    m_height = m_height DIVIDE_FS;
}


TestObject22::TestObject22():
    ImmovableObj()
{
    m_type = t_StationBlock;
    m_texture = TextureProvider::getInstance()->getTexture(m_type);
    SDL_QueryTexture(m_texture, NULL, NULL, &m_width, &m_height);
    m_width = m_width DIVIDE_FS;
    m_height = m_height DIVIDE_FS;
}



BackGround::BackGround():
    ImmovableObj()
{
    m_type = t_BACKGROUND;
    m_texture = TextureProvider::getInstance()->getTexture(m_type);
    SDL_QueryTexture(m_texture, NULL, NULL, &m_width, &m_height);
}

