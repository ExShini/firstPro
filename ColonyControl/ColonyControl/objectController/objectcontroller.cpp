#include "iostream"

#include "objectcontroller.h"
#include"objects/testobjects.h"
#include "mapGenarator/mapgenerator.h"

using namespace std;

ObjectController* ObjectController::m_instance = new ObjectController();

/*************************************
FUNC: ObjectController()
DESC: constructor
*************************************/
ObjectController::ObjectController():
    m_player(NULL)
{
}

/*************************************
FUNC: init()
DESC: initialize all start objects and over required for ObjectController
*************************************/
void ObjectController::init()
{
    MapGenerator* mapGen = new MapGenerator();
    m_plMap = mapGen->generateMap(Base);

    m_backGround = new BackGround();
    m_backGround->setX(0);
    m_backGround->setY(0);

    TestObject11* to1 = new TestObject11();
    to1->setX(10);
    to1->setY(10);

    m_player = to1;
    map<int, GObject*>* topMap = m_plMap->objects[MLEVEL_2];
    (*topMap)[ObjectController::getFieldKey(to1->getX(),to1->getY())] = to1;

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
FUNC: getPlayer()
DESC: return player (camera) object
*************************************/
GObject* ObjectController::getPlayer()
{
    return m_player;
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
FUNC: getFieldKey(genMapField *field)
DESC: calculate and return key for genMapField by coordinate
*************************************/
int ObjectController::getFieldKey(int x, int y)
{
    return y * GENERATED_MAP_WIDTH + x;
}


