#ifndef OBJECTCONTROLLER_H
#define OBJECTCONTROLLER_H

#include "gobject.h"
#include "list"

using namespace std;

class ObjectController
{
public:
    static ObjectController* getInstance();
    list<GObject*>* getObjectList();

    void init();

protected:
    ObjectController();
    static ObjectController* m_instance;
    list<GObject*>* m_OList;
};

#endif // OBJECTCONTROLLER_H
