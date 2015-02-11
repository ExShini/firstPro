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

	IController * m_controllers[e_Numbers_of_Controllers];

	MailController();
	~MailController();





};

#endif // MAILCONTROLLER_H