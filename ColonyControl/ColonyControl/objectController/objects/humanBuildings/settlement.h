#ifndef SETTLEMENT_H
#define SETTLEMENT_H

#ifdef WIN32
#include "../building.h"
#else
#include "objectController/objects/building.h"
#endif

class Settlement: public Buildings
{
public:
    Settlement(Sector* sector, int playerID);

    virtual int sendColonists(int maxColonists);
    virtual void inviteColonists(int colonists);
    virtual void process();

protected:

    int m_immigrants;
    int m_emigrants;

    bool m_readyToMove;

    int m_stateCount;
    int m_level;



    //infrastructure members
    int m_infrastructure;
    int m_lowInfLevel;
    int m_topInfLevel;

    void checkState();
    void foodEmigartion();
    void popLimitEmigration();
    void immigrationReq();

    //militaryPower, Energy and etc.
};

#endif // SETTLEMENT_H
