#ifndef BUILDING_H
#define BUILDING_H

#include "sector.h"

class Buildings : public GObject
{
public:
    Buildings(Sector* sector, int playerID) { m_sector = sector; m_playerID = playerID; }
    int getPopulation()         { return m_population; }
    int getFood()               { return m_food; }
    int getMinerals()           { return m_minerals; }
    int getProduction()         { return m_production; }
    void setPopulation(int value)       { m_population = value; }
    void setFood(int value)             { m_food = value; }
    void setMinerals(int value)         { m_minerals = value; }
    void setProduction(int value)       { m_production = value; }

    virtual int sendColonists(int maxColonists) = 0;
    virtual void inviteColonists(int colonists) = 0;
    virtual void process() = 0;

    int getPlayerID() { return m_playerID; }

protected:
    int m_population;             //current number of settlers
    int m_populationLimit;    //maximum base number of settlers, which can live at this sector
    int m_food;                   //food storage

    int m_minerals;               //mineral storage
    int m_production;             //production storage

    int m_colonists;
    int m_moveDesire;

    Sector* m_sector;


    int m_playerID;
};


#endif // BUILDING_H
