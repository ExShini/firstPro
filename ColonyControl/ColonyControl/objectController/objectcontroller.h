#ifndef OBJECTCONTROLLER_H
#define OBJECTCONTROLLER_H

#include "gobject.h"
#include "objectController/mapGenarator/module.h"

using namespace std;

class ObjectController
{
public:
    static ObjectController* getInstance();
    Module* getModule();
    GObject* getPlayer();
    GObject* getBackGround();
    void init();

    static int getFieldKey(int x, int y);

protected:
    ObjectController();
    static ObjectController* m_instance;
    Module* m_module;

    GObject * m_player;
    GObject * m_backGround;
};

#endif // OBJECTCONTROLLER_H
