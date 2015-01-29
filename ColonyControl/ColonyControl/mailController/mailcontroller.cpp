#include <iostream>
#include "mailcontroller.h"

#ifdef WIN32
#include "../objectController/objectcontroller.h"
#include "../gameProcessor/playercontroller.h"
#include "../gameProcessor/unitcontroller.h"
#else
#endif

using namespace std;

MailController* MailController::m_instance = new MailController();

MailController::MailController()
{
}

void MailController::Init()
{
	
	m_objController = ObjectController::getInstance();
	m_playerController = PlayerController::getInstance();
	m_unitController = UnitController::getInstance();
	
}

MailController* MailController::getInstance()
{
	return m_instance;
}

MailController::~MailController()
{
}

Message* MailController::sendMessage(Controllers addres, Message* message)
{
	Message* response = NULL;
	switch (addres)
	{
	case e_NoneController:
		cout << "ERROR! MailController::sendMessage:: e_NoneController addres!" << endl;
		break;
	case e_Render:
		break;
	case e_ObjectController:
		break;
	case e_UnitController:
		//response = m_unitController.ReseveMessage(message);
		break;
	case e_PlayerController:
		break;
	case e_UIController:
		break;
	case e_GameProcessor:
		break;
	default:
		cout << "ERROR! MailController::sendMessage:: Unvalide mail addres!" << endl;
		break;
	}
}