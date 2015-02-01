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

#endif // MESSAGE_H