#ifndef SECTOR_H
#define SECTOR_H
#include "objectController/gobject.h"

class Sector: public GObject
{
public:
    Sector();

    int getPopulation()         { return m_population; }
    int getFood()               { return m_food; }
    int getFertility()          { return m_fertility; }
    int getMinerals()           { return m_minerals; }
    int getMineralWealth()      { return m_mineralWealth; }
    int getProduction()         { return m_production; }

    void setPopulation(int value)       { m_population = value; }
    void setFood(int value)             { m_food = value; }
    void setFertility(int value)        { m_fertility = value; }
    void setMinerals(int value)         { m_minerals = value; }
    void setMineralWealth(int value)    { m_mineralWealth = value; }
    void setProduction(int value)       { m_production = value; }

protected:
    int m_population;             //current number of settlers
    // it moved to settlement
    //int m_populationBaseLimit;    //maximum base number of settlers, which can live at this sector
    int m_food;                   //food storage
    int m_fertility;              //maximum number of food, which can be base produced by settlers
    int m_minerals;               //mineral storage
    int m_mineralWealth;          //maximum number of minerals, which can be base produced by settlers
    int m_production;             //production storage

    //militaryPower, Energy and etc.
};

#endif // SECTOR_H
