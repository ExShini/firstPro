#include "door.h"
#include "enums/gui_enums.h"

Door::Door():
    ImmovableObj()
{
    m_type = t_Door;
    m_texture = TextureProvider::getInstance()->getTexture(m_type);
    SDL_QueryTexture(m_texture, NULL, NULL, &m_width, &m_height);
    m_width = m_width DIVIDE_FS;
    m_height = m_height DIVIDE_FS;
}
