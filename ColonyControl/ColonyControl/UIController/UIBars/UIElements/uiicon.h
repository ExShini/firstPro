#ifndef UIICON_H
#define UIICON_H

#ifdef WIN32
#include "../../../objectController/gobject.h"
#else
#include "objectController/gobject.h"
#endif

class UIIcon: public GObject
{
public:
    UIIcon(ObjectsType IconType);
};

#endif // UIICON_H
