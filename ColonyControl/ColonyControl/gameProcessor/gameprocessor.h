#ifndef GAMEPROCESSOR_H
#define GAMEPROCESSOR_H

#ifdef WIN32
#include "../objectController/objectList.h"
#include "../TimeManager/timeguard.h"
#else
#include "objectController/objectList.h"
#include "TimeManager/timeguard.h"
#endif

#include "unitcontroller.h"


class ObjectController;

class GameProcessor
{
public:

    static GameProcessor* getInstance();
    void init();
    void process();
    bool addSettlementToProcess(Settlement* sett);
    void tryColonize(int x, int y, int colonists);
    void removeSettlementFromProcess(int key);

    static int getFieldKey(int x, int y);

protected:
    static GameProcessor* m_instance;

    GameProcessor();
    ObjectController* m_objController;
    UnitController* m_unitController;
    map<int, Settlement*> m_processMap;

    int m_eventID;
    TimeGuard* m_timeGuard;

    void provideMovingCoordinat(int* x, int* y, Settlement* set);
};

#endif // GAMEPROCESSOR_H
