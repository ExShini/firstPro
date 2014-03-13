#include "objectcontroller.h"
#include"testobjects.h"

ObjectController* ObjectController::m_instance = new ObjectController();

ObjectController::ObjectController()
{
    m_OList = new list<GObject*>();

    TestObject11* to1 = new TestObject11();
    to1->setX(50);
    to1->setY(50);
    to1->setH(8);
    to1->setW(8);


    TestObject22* to2 = new TestObject22();
    to2->setX(150);
    to2->setY(50);
    to2->setH(8);
    to2->setW(8);

    m_OList->push_back(to1);
    m_OList->push_back(to2);
}

list<GObject*>* ObjectController::getObjectList()
{
    return m_OList;
}

ObjectController* ObjectController::getInstance()
{
    return m_instance;
}
