#ifndef INFOBAR_H
#define INFOBAR_H

#ifdef WIN32
#include "../uibar.h"
#include "../../objectController/objectcontroller.h"
#else
#include "UIController/uibar.h"
#include "objectController/objectcontroller.h"
#endif

class InfoBar: public UIBar
{
public:
    InfoBar();
    void UpdateInfo();

protected:
    TargetObject* m_target;
    ObjectController* m_objController;
};

#endif // INFOBAR_H
