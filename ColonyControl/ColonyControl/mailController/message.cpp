#include "message.h"

Message::Message(Controllers addr, MailType mailType) :
	addres(addr),
	type(mailType)
{
}

Message::~Message()
{

}