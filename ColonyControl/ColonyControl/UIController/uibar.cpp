#include "uibar.h"

UIBar::UIBar():
    GObject()
{
}

vector<GObject *> &UIBar::getElements()
{
    return m_elements;
}
