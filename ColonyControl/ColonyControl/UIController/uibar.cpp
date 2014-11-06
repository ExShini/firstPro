#include "uibar.h"

UIBar::UIBar():
    UIElement()
{
}

vector<UIElement*>* UIBar::getElements()
{
    return & m_elements;
}
