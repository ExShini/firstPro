#include "uielement.h"

UIElement::UIElement()
{

}


int UIElement::getX()
{
    return m_x;
}

int UIElement::getY()
{
    return m_y;
}

FrameController* UIElement::getFController()
{
    return m_frController;
}

void UIElement::setX(int x)
{
    m_x = x;
}

void UIElement::setY(int y)
{
    m_y = y;
}
