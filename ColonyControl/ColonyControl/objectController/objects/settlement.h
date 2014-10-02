#ifndef SETTLEMENT_H
#define SETTLEMENT_H
#include "objectController/gobject.h"
#include "sector.h"

class Settlement: public GObject
{
public:
    Settlement(Sector* sector);


    int getPopulation()         { return m_population; }
    int getFood()               { return m_food; }
    int getMinerals()           { return m_minerals; }
    int getProduction()         { return m_production; }
    void setPopulation(int value)       { m_population = value; }
    void setFood(int value)             { m_food = value; }
    void setMinerals(int value)         { m_minerals = value; }
    void setProduction(int value)       { m_production = value; }

    void process();
    int sendColonists();
    void inviteColonists(int colonists);

    bool readyToMove;

protected:

    int m_population;             //current number of settlers
    int m_populationBaseLimit;    //maximum base number of settlers, which can live at this sector
    int m_food;                   //food storage

    int m_minerals;               //mineral storage
    int m_production;             //production storage

    int m_colonists;
    int m_moveDesire;

    Sector* m_sector;

    //militaryPower, Energy and etc.
};

#endif // SETTLEMENT_H