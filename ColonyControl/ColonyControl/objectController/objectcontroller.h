#ifndef OBJECTCONTROLLER_H
#define OBJECTCONTROLLER_H

#include "gobject.h"
#include "objectController/mapGenarator/planetmap.h"
#include "objectList.h"
#include "gameProcessor/gameprocessor.h"

using namespace std;

class ObjectController
{
public:
    static ObjectController* getInstance();
    PlanetMap* getPlanetMap();
    GObject* getCamera();
    GObject* getBackGround();
    void init();

    bool addNewSettlement(int x, int y, int settlers);
    bool checkAreaApplicable(int x, int y);

protected:
    ObjectController();
    static ObjectController* m_instance;
    PlanetMap* m_plMap;

    GObject * m_cameraObj;
    GObject * m_backGround;

    GameProcessor* m_gameProc;

};

#endif // OBJECTCONTROLLER_H
