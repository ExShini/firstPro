#ifndef HUMSHUTLERETURNTOBASEPROC_H
#define HUMSHUTLERETURNTOBASEPROC_H
#include "unitprocessor.h"

class HumShutleReturnToBaseProc: public UnitProcessor
{
public:
    HumShutleReturnToBaseProc(Unit* unit);
    void process();
};

#endif // HUMSHUTLERETURNTOBASEPROC_H
