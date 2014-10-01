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
DESC: initialize all start objects and over required for ObjectController
*************************************/
void ObjectController::init()
{
    MapGenerator* mapGen = new MapGenerator();
    m_plMap = mapGen->generateMap(LavaPlanet);

    m_gameProc = GameProcessor::getInstance();

    m_backGround = new BackGround();
    m_backGround->setX(0);
    m_backGround->setY(0);

    CameraObject* to1 = new CameraObject();
    to1->setX(10);
    to1->setY(10);
    m_cameraObj = to1;

    addNewSettlement(10, 10, 500);
    addNewSettlement(60, 60, 500);
    addNewSettlement(10, 60, 500);
    addNewSettlement(60, 10, 500);

    //add to1 object to drawing camera object
    //Layer* topMap = m_plMap->objects[MLEVEL_2];
    //topMap->lMap[to1->getX()][to1->getY()] = to1;
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
GObject* ObjectController::getCamera()
{
    return m_cameraObj;
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
FUNC: addNewSettlement(int x, int y, int settlers)
DESC: add new settlement to game map (in x,y corr) with settlers
*************************************/
bool ObjectController::addNewSettlement(int x, int y, int settlers)
{
    //Check area for new settlement. If it already contain settlement return false.
    if (m_plMap->objects[SETTLEMENT_LEVEL]->lMap[x][y] != NULL)
        return false;

    //take sector and create new settelment

    Sector* sector = (Sector*)m_plMap->objects[SECTOR_LEVEL]->lMap[x][y];
    if (!sector->itApplicable())
        return false;

    Settlement* settelment = new Settlement(sector);
    settelment->setPopulation(settlers);

    //set new sector to game map and processMap
    m_plMap->objects[SETTLEMENT_LEVEL]->lMap[x][y] = settelment;
    m_gameProc->addSettlementToProcess(settelment);

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
