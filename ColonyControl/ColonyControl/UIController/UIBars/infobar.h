#ifndef INFOBAR_H
#define INFOBAR_H

#ifdef WIN32
#include "../uibar.h"
#else
#include "UIController/uibar.h"
#endif

class InfoBar: public UIBar
{
public:
    InfoBar();
};

#endif // INFOBAR_H
