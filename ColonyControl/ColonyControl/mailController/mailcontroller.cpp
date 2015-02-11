#include <iostream>
#include "mailcontroller.h"

#ifdef WIN32
//#include "../objectController/objectcontroller.h"
//#include "../gameProcessor/playercontroller.h"
#include "../gameProcessor/unitcontroller.h"
#else
#endif

using namespace std;

MailController* MailController::m_instance = new MailController();

MailController::MailController()
{
	for (int i = 0; i < e_Numbers_of_Controllers; i++)
	{
		m_controllers[i] = NULL;
	}
}

void MailController::Init()
{
	m_controllers[e_UnitController] = UnitController::getInstance();


	//m_objController = ObjectController::getInstance();
	//m_playerController = PlayerController::getInstance();
}

MailController* MailController::getInstance()
{
	return m_instance;
}

MailController::~MailController()
{
}

Message* MailController::sendMessage(Message* message)
{
	Message* response = NULL;

	if (message == NULL)
	{
		cout << "MailController::sendMessage: Error!!! NULL message!" << endl;
		return NULL;
	}

	Controllers addres = message->addres;

	if (addres == e_NoneController)
	{
		cout << "ERROR! MailController::sendMessage:: e_NoneController addres!" << endl;
		return NULL;
	}

	IController* controller = m_controllers[addres];

	if (controller != NULL)
	{
		response = controller->ReseveMessage(message);
	}

	return response;
}