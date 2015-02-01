#ifndef I_CONTROLLER_H
#define I_CONTROLLER_H
#include "mailController\message.h"

class IController
{
public:
	~IController();
	virtual Message* ReseveMessage(Message* message) = 0;
	IController();
};
#endif // I_CONTROLLER_H