#ifndef HUMSHUTLEIMMIGRATEPROC_H
#define HUMSHUTLEIMMIGRATEPROC_H

#include "unitprocessor.h"

class HumShutleEmigrationProc: public UnitProcessor
{
public:
    HumShutleEmigrationProc(Unit* unit);
    void process();

protected:
    void findTagertImmgrateColonists();
};

#endif // HUMSHUTLEIMMIGRATEPROC_H
