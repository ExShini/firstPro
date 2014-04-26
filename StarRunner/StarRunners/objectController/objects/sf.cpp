#include "sf.h"
#include "enums/gui_enums.h"

SF::SF():
    MovableObj()
{
    m_type = t_SF;
    m_texture = TextureProvider::getInstance()->getTexture(m_type);
    SDL_QueryTexture(m_texture, NULL, NULL, &m_width, &m_height);
    m_width = m_width DIVIDE_FS;
    m_height = m_height DIVIDE_FS;
}
