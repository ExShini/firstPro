#include "uibar.h"

UIBar::UIBar():
    GObject()
{
}

map<UIElementType, GObject *> &UIBar::getElements()
{
    return m_elements;
}
