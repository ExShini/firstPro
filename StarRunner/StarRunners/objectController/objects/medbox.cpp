#include "medbox.h"
#include "enums/gui_enums.h"

MedBox::MedBox():
    ImmovableObj()
{
    m_type = t_MedBox;
    m_texture = TextureProvider::getInstance()->getTexture(m_type);
    SDL_QueryTexture(m_texture, NULL, NULL, &m_width, &m_height);
    m_width = m_width DIVIDE_FS;
    m_height = m_height DIVIDE_FS;
}
