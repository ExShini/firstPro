#ifndef SECTOR_H
#define SECTOR_H
#include "objectController/gobject.h"

class Sector: public GObject
{
public:
    Sector();

    int getFertility()          { return m_fertility; }
    int getMineralWealth()      { return m_mineralWealth; }

    void setFertility(int value)        { m_fertility = value; }
    void setMineralWealth(int value)    { m_mineralWealth = value; }

    void init();

protected:


    int m_fertility;              //fertility for this sector. Food production depent of this parameter.
    int m_mineralWealth;          //maximum number of minerals, which can be base produced by settlers

};

#endif // SECTOR_H
