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

    TestObject11* to1 = new TestObject11();
    to1->setX(0);
    to1->setY(0);

    m_player = to1;
    m_OList->push_back(to1);

    for (int i = 0; i < 50; i++)
    {

        TestObject22* to2 = new TestObject22();
        to2->setX(3 + i * to2->getW() );
        to2->setY(2);

        m_OList->push_back(to2);
    }

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



