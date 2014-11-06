#ifndef GAMEPROCESSOR_H
#define GAMEPROCESSOR_H

#ifdef WIN32
#include "../objectController/objectList.h"
#include "../TimeManager/timeguard.h"
#else
#include "objectController/objectList.h"
#include "TimeManager/timeguard.h"
#endif

#include "playercontroller.h"
#include "unitcontroller.h"


class ObjectController;

class GameProcessor
{
public:

    static GameProcessor* getInstance();
    void init();
    void process();

    void addNewPlayer(int x, int y, int race);

    bool addBuildingToProcess(Buildings *sett);
    int tryGetColonists(int x, int y, int maxCol, int playerID);
    bool tryColonize(int x, int y, int colonists, int playerID);
    void removeSettlementFromProcess(int key);
    void checkEmptyAreas(int x, int y, int playerID);

    static int getFieldKey(int x, int y);

protected:
    static GameProcessor* m_instance;

    GameProcessor();
    ObjectController* m_objController;
    UnitController* m_unitController;
    map<int, Buildings*> m_processMap;

    int m_eventID;
    TimeGuard* m_timeGuard;
    PlayerController* m_plController;

    void TryAddAreaForColonize(int x, int y, Player* player);
};

#endif // GAMEPROCESSOR_H
