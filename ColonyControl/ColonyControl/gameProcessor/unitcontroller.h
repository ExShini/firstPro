#ifndef UNITCONTROLLER_H
#define UNITCONTROLLER_H

#ifdef WIN32
#include "../enums/gameProcessingSettings.h"
#include "../TimeManager/timeguard.h"
#else
#include "enums/gameProcessingSettings.h"
#include "TimeManager/timeguard.h"
#endif



#include "list"
#include "unit.h"

using namespace std;

class UnitController
{
public:
    static UnitController* getInstance();
    void init();
    void process();
    void addUnit(Unit*unit);
    list<Unit*>* getUnitList() { return m_units; }

protected:
    static UnitController* m_instance;
    UnitController();
    list<Unit*>* m_units;
    list<list<Unit*>::iterator>* m_unitsToDelete;

    void cleanProcList();

    int m_eventIDs[UNIT_PROC_RATE];
    TimeGuard* m_timeGuard;
    int m_currTimeStep;
};

#endif // UNITCONTROLLER_H
