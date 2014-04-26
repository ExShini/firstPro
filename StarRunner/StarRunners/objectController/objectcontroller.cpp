#include "objectcontroller.h"
#include"objects/testobjects.h"
#include "objects/wall.h"
#include "mapGenarator/modulegenerator.h"

ObjectController* ObjectController::m_instance = new ObjectController();

ObjectController::ObjectController():
    m_player(NULL)
{
}

void ObjectController::init()
{
    moduleGenerator* modGen =  new moduleGenerator();
    m_module = modGen->generateModule(ResidentialUnit);



    m_backGround = new BackGround();
    m_backGround->setX(0);
    m_backGround->setY(0);

    TestObject11* to1 = new TestObject11();
    to1->setX(10);
    to1->setY(10);

    m_player = to1;
    map<int, GObject*>* topMap = m_module->objects[MLEVEL_2];
    (*topMap)[ObjectController::getFieldKey(to1->getX(),to1->getY())] = to1;

}

Module *ObjectController::getModule()
{
    return m_module;
}

GObject* ObjectController::getPlayer()
{
    return m_player;
}

GObject* ObjectController::getBackGround()
{
    return m_backGround;
}

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


