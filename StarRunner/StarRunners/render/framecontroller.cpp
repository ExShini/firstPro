#include "iostream"

#include "framecontroller.h"
#include "enums/gui_enums.h"

using namespace std;

FrameController::FrameController(SDL_Texture* texture, Direction dir = DOWN):
    m_direction(dir)
{
    m_texture = texture;
}


SDL_Texture* FrameController::getTexture()
{
    return m_texture;
}

SDL_Rect FrameController::getSrcRect()
{
    //draft version
    SDL_Rect pos;
    pos.w = FIELD_SIZE;
    pos.h = FIELD_SIZE;

    pos.x = 0;

    switch (m_direction) {
    case DOWN:
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
