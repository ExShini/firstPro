#include "testobjects.h"

TestObject1::TestObject1()
{
    m_type = TestObject1;
    m_texture = TextureProvider.getInstance()->getTexture(m_type);
}

SDL_Texture* TestObject1::getTexture()
{
    return m_texture;
}


TestObject2::TestObject1()
{
    m_type = TestObject2;
    m_texture = TextureProvider.getInstance()->getTexture(m_type);
}

SDL_Texture* TestObject2::getTexture()
{
    return m_texture;
}
