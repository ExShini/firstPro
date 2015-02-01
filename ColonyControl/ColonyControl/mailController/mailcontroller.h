#ifndef MAILCONTROLLER_H
#define MAILCONTROLLER_H

#include "message.h"

#ifdef WIN32
#include "../icontroller.h"
#else
#include "icontroller.h"
#endif

class MailController
{
public:
	static MailController * getInstance();
	void Init();

	Message* sendMessage(Message* message);

protected:
	//instances
	static MailController * m_instance;

	IController * m_objController;
	IController * m_unitController;
	IController * m_playerController;

	MailController();
	~MailController();





};

#endif // MAILCONTROLLER_H