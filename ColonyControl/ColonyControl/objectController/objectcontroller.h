#ifndef OBJECTCONTROLLER_H
#define OBJECTCONTROLLER_H

#ifdef WIN32
#include "gobject.h"
#include "mapGenarator/planetmap.h"
#include "objectList.h"
#include "../gameProcessor/gameprocessor.h"
#else
#include "gobject.h"
#include "objectController/mapGenarator/planetmap.h"
#include "objectList.h"
#include "gameProcessor/gameprocessor.h"
#endif



using namespace std;

class ObjectController
{
public:
    static ObjectController* getInstance();
    PlanetMap* getPlanetMap();
    CameraObject* getCamera();
    TargetObject* getTarget();

    GObject* getBackGround();
    void init();

    bool addNewBuilding(Buildings* building);
    bool checkAreaApplicable(int x, int y);

protected:
    ObjectController();
    static ObjectController* m_instance;
    PlanetMap* m_plMap;

    CameraObject * m_cameraObj;
    TargetObject * m_targetObj;
    GObject * m_backGround;

    GameProcessor* m_gameProc;

};

#endif // OBJECTCONTROLLER_H
