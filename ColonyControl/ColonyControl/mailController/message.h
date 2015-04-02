#ifndef MESSAGE_H
#define MESSAGE_H

#ifdef WIN32
#include "../enums/mailing/mailsettings.h"
#include "../enums/objects.h"
#else
#include "enums/mailing/mailsettings.h"
#include "enums/objects.h"
#endif

class Buildings;
class GObject;
class Unit;

/**********************************************/

class Message
{
public:
	Message(Controllers addr, MailType mailType);
	virtual ~Message();
	
	Controllers addres;
	MailType type;
};


/**********************************************/

class CreateUnitMessage: public Message
{
public:
	CreateUnitMessage(ObjectsType UnitType, Buildings * Base);
	~CreateUnitMessage();

	Buildings* base;
	ObjectsType unitType;
};

/**********************************************/

class GObjectMessage : public Message
{
public:
	GObjectMessage(Controllers addr, GObject * Object);
	GObjectMessage(GObject * Object);
	~GObjectMessage();

	GObject * object;

};

/**********************************************/

class UnittMessage : public Message
{
public:
	UnittMessage(Controllers addr, Unit * Unit);
	UnittMessage(Unit * unit);
	~UnittMessage();

	Unit * unit;

};

/**********************************************/

class TargetRequestMessage : public Message
{
public:
	TargetRequestMessage(ObjectsType UnitType, GObject* StartSector, int PlayerID);
	~TargetRequestMessage();

	GObject * startSector;
	ObjectsType unitType;
	int playerID;

};

#endif // MESSAGE_H