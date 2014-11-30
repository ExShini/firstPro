#ifndef UIBAR_H
#define UIBAR_H
#include "map"

#ifdef WIN32
#include "../gobject.h"
#else
#include "objectController/gobject.h"
#endif


using namespace std;

class UIBar: public GObject
{
public:
    map<UIElementType, GObject*>& getElements();

protected:
    UIBar();
    map<UIElementType, GObject*> m_elements;
};

#endif // UIBAR_H
