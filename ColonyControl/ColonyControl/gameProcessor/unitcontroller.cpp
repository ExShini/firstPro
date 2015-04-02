#include "iostream"
#include "unitcontroller.h"
#include "unitfactory.h"

#ifdef WIN32
#include "../objectController/objects/building.h"
#else
#include "objectController/objects/building.h"
#endif

using namespace std;

UnitController* UnitController::m_instance = new UnitController();

UnitController::UnitController() :
	IController()
{
    m_units = new list<Unit*>();
    m_unitsToDelete = new list<list<Unit*>::iterator>();
	m_unitFactory = new UnitFactory();
}

void UnitController::init()
{
    m_timeGuard = TimeGuard::getInstance();
    m_currTimeStep = 0;
    int timePoint;
    int step = SEC1 / UNIT_PROC_RATE;
    for (int i = 0; i < UNIT_PROC_RATE; i++)
    {
        timePoint = DEFAULT_PROC_TIME_POINT + i * step;
        m_eventIDs[i] = m_timeGuard->addEvent(timePoint);
    }


}

UnitController* UnitController::getInstance()
{
    return m_instance;
}

void UnitController::addUnit(Unit * unit)
{
    m_units->push_back(unit);
}

void UnitController::process()
{
    int evID = m_eventIDs[m_currTimeStep];
    if (!m_timeGuard->checkEvent(evID, true))
        return;

    m_currTimeStep++;
    if (m_currTimeStep >= UNIT_PROC_RATE)
        m_currTimeStep = 0;

    cleanProcList();

    list<Unit*>::iterator iter = m_units->begin();
    list<Unit*>::iterator end = m_units->end();

    for (; iter != end; iter++)
    {
        Unit* unit = (Unit*)(*iter);
        unit->process();

        if (!unit->isActive())
        {
            list<Unit*>::iterator toDel = iter;
            m_unitsToDelete->push_back(toDel);
        }
    }
}

void UnitController::cleanProcList()
{
    list<list<Unit*>::iterator>::iterator iter = m_unitsToDelete->begin();
    list<list<Unit*>::iterator>::iterator end = m_unitsToDelete->end();

    for (; iter != end ; iter++)
    {
        list<Unit*>::iterator delIter = (list<Unit*>::iterator)(*iter);
        Unit* unit = (Unit*)(*delIter);
        delete unit;
        m_units->erase(delIter);
    }

    m_unitsToDelete->clear();
}

Message* UnitController::ReseveMessage(Message* message)
{
	Message* response = NULL;

	switch (message->type)
	{
	case e_NoneMailType:
	{
		cout << "ERROR!!! UnitController::ReseveMessage: NoneMailType message!" << endl;
		break;
	}
	case e_Response:
		break;
	case e_CreateUnit:
	{
		CreateUnitMessage * createUMessage = static_cast<CreateUnitMessage*>(message);
		Unit* unit = m_unitFactory->createUnit(createUMessage->unitType, createUMessage->base);
		if (unit != NULL)
		{
			addUnit(unit);
			response = new UnittMessage(unit);
		}
		break;
	}
	default:
		cout << "ERROR!!! UnitController::ReseveMessage: Unused type of message!" << endl;
		break;
	}

	//clear memory 
	delete message;

	return response;
}