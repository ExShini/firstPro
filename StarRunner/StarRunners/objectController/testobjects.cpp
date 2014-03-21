#include "testobjects.h"
#include "enums/gui_enums.h"

TestObject11::TestObject11():
    MovableObj()
{
    m_type = TestObject1;
    m_texture = TextureProvider::getInstance()->getTexture(m_type);
    SDL_QueryTexture(m_texture, NULL, NULL, &m_width, &m_height);
    m_width = m_width DIVIDE_FS;
    m_height = m_height DIVIDE_FS;
}

SDL_Texture* TestObject11::getTexture()
{
    return m_texture;
}


TestObject22::TestObject22():
    ImmovableObj()
{
    m_type = Floor;
    m_texture = TextureProvider::getInstance()->getTexture(m_type);
    SDL_QueryTexture(m_texture, NULL, NULL, &m_width, &m_height);
    m_width = m_width DIVIDE_FS;
    m_height = m_height DIVIDE_FS;
}

SDL_Texture* TestObject22::getTexture()
{
    return m_texture;
}



BackGround::BackGround():
    ImmovableObj()
{
    m_type = BACKGROUND;
    m_texture = TextureProvider::getInstance()->getTexture(m_type);
    SDL_QueryTexture(m_texture, NULL, NULL, &m_width, &m_height);
}

SDL_Texture* BackGround::getTexture()
{
    return m_texture;
}
