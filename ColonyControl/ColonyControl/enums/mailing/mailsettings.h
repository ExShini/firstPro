#ifndef MAIL_SETTINGS_H
#define MAIL_SETTINGS_H

enum MailType
{
	e_NoneMailType,
	e_Response
};

enum Controllers
{
	e_NoneController = 0,
	e_Render,
	e_ObjectController,
	e_UnitController,
	e_PlayerController,
	e_UIController,
	e_GameProcessor
};

#endif // MAIL_SETTINGS_H