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


/**** GObjectMessage ****/
/**********************************************/

GObjectMessage::GObjectMessage(GObject * Object):
	Message(e_NoneController, e_GObjectMessage)
{
	this->object = Object;
}

GObjectMessage::GObjectMessage(Controllers addr, GObject * Object) :
Message(addr, e_GObjectMessage)
{
	this->object = Object;
}

GObjectMessage::~GObjectMessage()
{
}

/**** UnittMessage ****/
/**********************************************/

UnittMessage::UnittMessage(Unit * Unit) :
Message(e_NoneController, e_UnitMessage)
{
	this->unit = Unit;
}

UnittMessage::UnittMessage(Controllers addr, Unit * Unit) :
Message(addr, e_GObjectMessage)
{
	this->unit = Unit;
}

UnittMessage::~UnittMessage()
{
}

/**** TargetRequestMessage ****/
/**********************************************/

TargetRequestMessage::TargetRequestMessage(ObjectsType UnitType, GObject* StartSector, int PlayerID):
	Message(e_PlayerController, e_TargetRequest)
{
	unitType = UnitType;
	startSector = StartSector;
	playerID = PlayerID;
}

TargetRequestMessage::~TargetRequestMessage()
{

}