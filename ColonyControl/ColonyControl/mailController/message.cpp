#include "message.h"

#ifdef WIN32
#include "../enums/objects.h"
#else
#include "enums/objects.h"
#endif

/**** Message ****/
/**********************************************/
Message::Message(Controllers addr, MailType mailType) :
	addres(addr),
	type(mailType)
{
}

Message::~Message()
{

}


/**** CreateUnitMessage ****/
/**********************************************/

CreateUnitMessage::CreateUnitMessage(ObjectsType UnitType, Buildings * Base) :
	Message(e_UnitController, e_CreateUnit)
{
	this->unitType = UnitType;
	this->base = Base;
}

CreateUnitMessage::~CreateUnitMessage()
{
}