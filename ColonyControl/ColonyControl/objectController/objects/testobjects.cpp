#include "testobjects.h"

#ifdef WIN32
#include "../../enums/gui_enums.h"
#else
#include "enums/gui_enums.h"
#endif


CameraObject::CameraObject():
    MovableObj()
{
    m_type = t_CameraObject;
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

