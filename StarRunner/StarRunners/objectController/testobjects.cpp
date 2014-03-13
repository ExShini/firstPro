#include "testobjects.h"

TestObject11::TestObject11():
    GObject()
{
    m_type = TestObject1;
    m_texture = TextureProvider::getInstance()->getTexture(m_type);
}

SDL_Texture* TestObject11::getTexture()
{
    return m_texture;
}


TestObject22::TestObject22():
    GObject()
{
    m_type = TestObject2;
    m_texture = TextureProvider::getInstance()->getTexture(m_type);
}

SDL_Texture* TestObject22::getTexture()
{
    return m_texture;
}



BackGround::BackGround():
    GObject()
{
    m_x = 0;
    m_y = 0;
    m_type = BACKGROUND;
    m_texture = TextureProvider::getInstance()->getTexture(m_type);
}

SDL_Texture* BackGround::getTexture()
{
    return m_texture;
}
