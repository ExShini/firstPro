#include "iostream"

#include "framecontroller.h"
#include "enums/gui_enums.h"

using namespace std;

/*************************************
FUNC: FrameController(SDL_Texture* texture, bool rotation, bool mooveble, Direction dir)
DESC: constructor
*************************************/
FrameController::FrameController(SDL_Texture* texture, bool rotation, bool mooveble, Direction dir):
    m_direction(dir)
{
    m_texture = texture;
    m_rotation = rotation;
    m_moveble = mooveble;
}

/*************************************
FUNC: setDirection(Direction dir)
DESC: set direction for current object
*************************************/
void FrameController::setDirection(Direction dir)
{
    m_direction = dir;
}

/*************************************
FUNC: getTexture()
DESC: return pointer on object texture
*************************************/
SDL_Texture* FrameController::getTexture()
{
    return m_texture;
}

/*************************************
FUNC: getSrcRect()
DESC: return rect with frame position for current moment
*************************************/
SDL_Rect FrameController::getSrcRect()
{
    if (m_rotation)
    {
        const SDL_Rect& pos = getCurrRect();
        return pos;
    }
    else
    {
        const SDL_Rect& pos = getFullRect();
        return pos;
    }
}

/*************************************
FUNC: getFullRect()
DESC: return rect for full texture
*************************************/
SDL_Rect FrameController::getFullRect()
{
    SDL_Rect pos;
    pos.x = 0;
    pos.y = 0;

    SDL_QueryTexture(m_texture, NULL, NULL, &pos.w, &pos.h);

    return pos;
}

/*************************************
FUNC: getCurrRect()
DESC: return rect with frame position for current moment
*************************************/
SDL_Rect FrameController::getCurrRect()
{
    SDL_Rect pos;
    pos.w = FIELD_SIZE;
    pos.h = FIELD_SIZE;

    pos.x = 0;

    switch (m_direction) {
    case DOWN:
    case NODIR:
        pos.y = 0;
        break;
    case UP:
        pos.y = FIELD_SIZE;
        break;
    case LEFT:
        pos.y = FIELD_SIZE * 2;
        break;
    case RIGHT:
        pos.y = FIELD_SIZE * 3;
        break;
    default:
        cout << "FrameController: try to use bad direction!";
        break;
    }

    return pos;
}
