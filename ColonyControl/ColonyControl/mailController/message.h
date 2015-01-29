#ifndef MESSAGE_H
#define MESSAGE_H

#ifdef WIN32
#include "../enums/mailing/mailsettings.h"
#else
#include "enums/mailing/mailsettings.h"
#endif

class Message
{
public:
	Message(Controllers addr, MailType mailType);
	virtual ~Message();
	
	Controllers addres;
	MailType type;
};

#endif // MESSAGE_H