#include "iostream"

#include "objectcontroller.h"

#include "mapGenarator/mapgenerator.h"

using namespace std;

ObjectController* ObjectController::m_instance = new ObjectController();

/*************************************
FUNC: ObjectController()
DESC: constructor
*************************************/
ObjectController::ObjectController():
    m_cameraObj(NULL)
{
}

/*************************************
FUNC: init()
DESC: initialize all iter objects and over required for ObjectController
*************************************/
void ObjectController::init()
{
    MapGenerator* mapGen = new MapGenerator();
    m_plMap = mapGen->generateMap(LavaPlanet);

    m_gameProc = GameProcessor::getInstance();

    m_backGround = new BackGround();
    m_backGround->setX(0);
    m_backGround->setY(0);

    CameraObject* cam = new CameraObject();
    cam->setX(10);
    cam->setY(10);
    m_cameraObj = cam;

    TargetObject* to = new TargetObject();
    to->setX(10);
    to->setY(10);
    m_targetObj = to;

}

/*************************************
FUNC: getPlanetMap()
DESC: return PlanetMap object
*************************************/
PlanetMap *ObjectController::getPlanetMap()
{
    return m_plMap;
}

/*************************************
FUNC: getCamera()
DESC: return player (camera) object
*************************************/
CameraObject *ObjectController::getCamera()
{
    return m_cameraObj;
}

/*************************************
FUNC: getTarget()
DESC: return player (camera) object
*************************************/
TargetObject *ObjectController::getTarget()
{
    return m_targetObj;
}

/*************************************
FUNC: getBackGround()
DESC: return background object
*************************************/
GObject* ObjectController::getBackGround()
{
    return m_backGround;
}

/*************************************
FUNC: getInstance()
DESC: return instance of ObjectController
*************************************/
ObjectController* ObjectController::getInstance()
{
    return m_instance;
}

/*************************************
FUNC: addNewBuilding(int x, int y, int settlers)
DESC: add new settlement to game map (in x,y corr) with settlers
*************************************/
bool ObjectController::addNewBuilding(Buildings* building)
{
    int x = building->getX();
    int y = building->getY();

    if(x < 0 || x >= MAP_WIDTH || y < 0 || y > MAP_HEIGHT)
        return false;

    //Check area for new buildings. If it already contain buildings return false.
    if (m_plMap->objects[SETTLEMENT_LEVEL]->lMap[x][y] != NULL)
        return false;

    //take sector and create new settelment

    Sector* sector = (Sector*)m_plMap->objects[SECTOR_LEVEL]->lMap[x][y];
    if (!sector->itApplicable())
        return false;

    //set new sector to game map and processMap
    m_plMap->objects[SETTLEMENT_LEVEL]->lMap[x][y] = building;
    m_gameProc->addBuildingToProcess(building);

    return true;
}

/*************************************
FUNC: checkAreaApplicable(int x, int y)
DESC: check this opportunity for use this area
*************************************/
bool ObjectController::checkAreaApplicable(int x, int y)
{
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT)
    {
        Sector* sector = (Sector*)m_plMap->objects[SECTOR_LEVEL]->lMap[x][y];
        if (sector != NULL)
            return sector->itApplicable();
    }

    return false;
}
