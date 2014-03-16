#include "objectcontroller.h"
#include"testobjects.h"

ObjectController* ObjectController::m_instance = new ObjectController();

ObjectController::ObjectController():
    m_player(NULL)
{
    m_OList = new list<GObject*>();
}

void ObjectController::init()
{
    m_backGround = new BackGround();
    m_backGround->setX(0);
    m_backGround->setY(0);
    m_backGround->setW(1280);
    m_backGround->setH(1152);

    TestObject11* to1 = new TestObject11();
    to1->setX(0);
    to1->setY(0);
    to1->setH(1);
    to1->setW(1);

    m_player = to1;

    TestObject22* to2 = new TestObject22();
    to2->setX(3);
    to2->setY(2);
    to2->setH(1);
    to2->setW(1);

    m_OList->push_back(to1);
    m_OList->push_back(to2);
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



