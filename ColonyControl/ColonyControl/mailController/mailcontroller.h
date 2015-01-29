#ifndef MAILCONTROLLER_H
#define MAILCONTROLLER_H

#include "message.h"

class ObjectController;
class UnitController;
class PlayerController;

class MailController
{
public:
	static MailController * getInstance();
	void Init();

	Message* sendMessage(Controllers addres, Message* message);

protected:
	//instances
	static MailController * m_instance;

	ObjectController * m_objController;
	UnitController * m_unitController;
	PlayerController * m_playerController;

	MailController();
	~MailController();





};

#endif // MAILCONTROLLER_H