#include "testobjects.h"
#include "enums/gui_enums.h"

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

