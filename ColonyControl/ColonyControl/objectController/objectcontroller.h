#ifndef OBJECTCONTROLLER_H
#define OBJECTCONTROLLER_H

#include "gobject.h"
#include "objectController/mapGenarator/planetmap.h"

using namespace std;

class ObjectController
{
public:
    static ObjectController* getInstance();
    PlanetMap* getPlanetMap();
    GObject* getPlayer();
    GObject* getBackGround();
    void init();

    static int getFieldKey(int x, int y);

protected:
    ObjectController();
    static ObjectController* m_instance;
    PlanetMap* m_plMap;

    GObject * m_player;
    GObject * m_backGround;
};

#endif // OBJECTCONTROLLER_H
