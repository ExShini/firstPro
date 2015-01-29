#ifndef SETTLEMENT_H
#define SETTLEMENT_H

#ifdef WIN32
#include "../building.h"
#include "../../../mailController/mailcontroller.h"
#else
#include "objectController/objects/building.h"
#include "mailController/mailcontroller.h"
#endif

class Settlement: public Buildings
{
public:
    Settlement(Sector* sector, int playerID);
    int getSettlementLevel() { return m_level; }
    int getSettlementInfr() { return m_infrastructure; }
    int getSettlementNextInfrBrd() { return m_topInfLevel; }

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

    virtual void checkState();
    void foodEmigartion();
    void popLimitEmigration();
    void immigrationReq();

    //militaryPower, Energy and etc.
};

#endif // SETTLEMENT_H
