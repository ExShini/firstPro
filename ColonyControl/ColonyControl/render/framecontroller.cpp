#include "iostream"

#include "framecontroller.h"

#ifdef WIN32
#include "../enums/gui_enums.h"
#else
#include "enums/gui_enums.h"
#endif


using namespace std;

/*************************************
FUNC: FrameController(SDL_Texture* texture, bool rotation, bool mooveble, Direction dir)
DESC: constructor
*************************************/
FrameController::FrameController(SDL_Texture* texture, bool fullTexture):
    m_fullTexture(fullTexture)
{
    m_texture = texture;
    setTextureArea(0,0);
}

/*************************************
FUNC: setNewTexture(SDL_Texture* texture, bool rotation, bool mooveble, Direction dir)
DESC: set new texture
*************************************/
void FrameController::setNewTexture(SDL_Texture *texture, bool fullTexture)
{
    m_fullTexture = fullTexture;
    m_texture = texture;
    setTextureArea(0,0);
}

/*************************************
FUNC: setDirection(Direction dir)
DESC: set direction for current object
*************************************/
void FrameController::setTextureArea(int x, int y)
{
    m_pos.w = FIELD_SIZE;
    m_pos.h = FIELD_SIZE;

    m_pos.x = x * FIELD_SIZE;
    m_pos.y = y * FIELD_SIZE;

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
    if(m_fullTexture)
    {
        const SDL_Rect& pos = getFullRect();
        return pos;
    }
    else
    {
        const SDL_Rect& pos = getCurrRect();
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
    return m_pos;
}
