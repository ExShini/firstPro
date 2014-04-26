#include "testobjects.h"
#include "enums/gui_enums.h"

TestObject11::TestObject11():
    MovableObj(t_TestObject1)
{
}


TestObject22::TestObject22():
    ImmovableObj(t_StationBlock)
{
}



BackGround::BackGround():
    ImmovableObj(t_BACKGROUND)
{
    SDL_QueryTexture(m_fcontroller->getTexture(), NULL, NULL, &m_width, &m_height);
}

