#ifndef HUMSHUTLEEMIGRATIONPROC_H
#define HUMSHUTLEEMIGRATIONPROC_H

#include "unitprocessor.h"

class HumShutleImmigrateProc: public UnitProcessor
{
public:
    HumShutleImmigrateProc(Unit* unit);
    void process();

protected:
    void findTagertImmgrateColonists();
};

#endif // HUMSHUTLEEMIGRATIONPROC_H
