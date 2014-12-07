#include "uiicon.h"

UIIcon::UIIcon(ObjectsType IconType):
    GObject()
{
    m_type = IconType;
    m_fcontroller = new FrameController(
                TextureProvider::getInstance()->getTexture(m_type), true);
}
