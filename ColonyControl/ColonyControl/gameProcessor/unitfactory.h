#ifndef UNIT_FACTORY_H
#define UNIT_FACTORY_H

#ifdef WIN32
#include "../enums/objects.h"
#else
#include "enums/objects.h"
#endif

class Buildings;
class Unit;
class MailController;

class UnitFactory
{
public:
	UnitFactory();
	~UnitFactory();

	Unit * createUnit(ObjectsType type, Buildings* base);

private:
	MailController * m_mailController;

};

#endif