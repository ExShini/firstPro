#include "specialObj.h"

#ifdef WIN32
#include "../../enums/gui_enums.h"
#else
#include "enums/gui_enums.h"
#endif

/***************************************************/
//CameraObject

CameraObject::CameraObject():
    MovableObj()
{
    m_type = t_CameraObject;
    m_fcontroller = new FrameController(
                TextureProvider::getInstance()->getTexture(m_type));
}

/***************************************************/
//TargetObject

TargetObject::TargetObject():
    MovableObj()
{
    m_type = t_TargetObject;
    m_fcontroller = new FrameController(
                TextureProvider::getInstance()->getTexture(m_type));
}


bool TargetObject::isValidLink()
{
    if(m_x < 0 && m_x >= MAP_WIDTH &&
       m_y < 0 && m_y >= MAP_HEIGHT)
    {
        return false;
    }

    return true;
}


/***************************************************/
//BackGround
BackGround::BackGround():
    ImmovableObj()
{
    m_type = t_BACKGROUND;
    m_fcontroller = new FrameController(
                TextureProvider::getInstance()->getTexture(m_type), true);
    SDL_QueryTexture(m_fcontroller->getTexture(), NULL, NULL, &m_width, &m_height);
}

