#ifndef UNITCONTROLLER_H
#define UNITCONTROLLER_H

#ifdef WIN32
#include "../enums/gameProcessingSettings.h"
#include "../TimeManager/timeguard.h"
#include "../icontroller.h"
#else
#include "enums/gameProcessingSettings.h"
#include "TimeManager/timeguard.h"
#endif



#include "list"
#include "unit.h"

using namespace std;

class UnitController: public IController
{
public:
    static UnitController* getInstance();
    void init();
    void process();
    void addUnit(Unit*unit);
    list<Unit*>* getUnitList() { return m_units; }

	virtual Message* ReseveMessage(Message* message);

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
