#ifndef UNITPROCESSOR_H
#define UNITPROCESSOR_H

#ifdef WIN32
#include "../../unit.h"
#else
#include "gameProcessor/unit.h"
#endif


class UnitProcessor
{
public:
    UnitProcessor(Unit* unit);
    virtual ~UnitProcessor();
    virtual void process() = 0;

protected:
    Unit* m_unit;
};

#endif // UNITPROCESSOR_H
