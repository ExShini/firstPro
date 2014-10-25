#ifndef HUMANCOLONISTS_H
#define HUMANCOLONISTS_H

#ifdef WIN32
#include "../unit.h"
#include "../gameprocessor.h"
#include "UnitProcessors/unitprocessor.h"
#else
#include "gameProcessor/unit.h"
#include "gameProcessor/gameprocessor.h"
#include "UnitProcessors/unitprocessor.h"
#endif


enum shutleState
{
    findEmigrants = 0,
    moveImmigrants,
    returnToBase,
    NumberOFShutlProc
};

class HumanColonists:  public Unit
{
public:
    HumanColonists(GObject *base, GObject *target, int playerID);
    ~HumanColonists();

    void setColonists(int col) { m_colonists = col; }
    void setDirection(GObject* target);

    void setStatuse(int status) { m_shutlState = status; }

    int getColonists() { return m_colonists; }
    int getSteps() { return m_steps; }
    int getTX() { return m_tx; }
    int getTY() { return m_ty; }
    GObject* getBase() { return m_base; }

    void process();

protected:
    int m_tx, m_ty;

    int m_xSpeed, m_ySpeed;
    int m_xCap, m_yCap;
    int m_steps;
    int m_colonists;

    GObject* m_base;
    int m_shutlState;
    UnitProcessor* m_processors[NumberOFShutlProc];

};


#endif // HUMANCOLONISTS_H
