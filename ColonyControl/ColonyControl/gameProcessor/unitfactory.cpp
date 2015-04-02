#include <iostream>
#include "unitfactory.h"
#include "allUnits.h"


#ifdef WIN32
#include "../mailController/mailcontroller.h"
#include "../objectController/objects/building.h"
#else
#include "mailController/mailcontroller.h"
#include "objectController/objects/building.h"
#endif

using namespace std;

UnitFactory::UnitFactory()
{
	m_mailController = MailController::getInstance();
}

UnitFactory::~UnitFactory()
{
}

Unit * UnitFactory::createUnit(ObjectsType type, Buildings* base)
{
	Unit * unit = NULL;

	TargetRequestMessage* message = new TargetRequestMessage(type, base, base->getPlayerID());
	GObjectMessage * resp = static_cast<GObjectMessage *> (m_mailController->sendMessage(message));

	if (resp == NULL)
	{
		cout << "UnitFactory::createUnit: Error! Null-response from PlayerController." << endl;
		return NULL;
	}

	if (resp->object != NULL)
	{
		switch (type)
		{
		case t_HumanShuttle:
		{
			unit = new HumanColonists(base, resp->object, base->getPlayerID());
			break;
		}
		case NULLOBJECT:
		{
			cout << "UnitFactory::createUnit: Error! NULLOBJECT type." << endl;
			break;
		}
		default:
			break;
		}
	}
		
	//clear memory
	delete resp;

	return unit;
}