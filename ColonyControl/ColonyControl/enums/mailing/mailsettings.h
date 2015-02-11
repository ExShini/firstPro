#ifndef MAIL_SETTINGS_H
#define MAIL_SETTINGS_H

enum MailType
{
	e_NoneMailType,
	e_Response,
	e_CreateUnit
};

enum Controllers
{
	e_NoneController = -1,
	e_Render = 0,
	e_ObjectController = 1,
	e_UnitController = 2,
	e_PlayerController = 3,
	e_UIController = 4,
	e_GameProcessor = 5,
	e_Numbers_of_Controllers
};

#endif // MAIL_SETTINGS_H