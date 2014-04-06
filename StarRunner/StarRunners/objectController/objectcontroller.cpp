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
    m_OList = modGen->generateModule(ResidentialUnit);



    m_backGround = new BackGround();
    m_backGround->setX(0);
    m_backGround->setY(0);

    TestObject11* to1 = new TestObject11();
    to1->setX(50);
    to1->setY(50);

    m_player = to1;
    m_OList->push_back(to1);

}

list<GObject*>* ObjectController::getObjectList()
{
    return m_OList;
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



