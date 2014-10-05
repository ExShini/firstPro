#ifndef HUMANCOLONISTS_H
#define HUMANCOLONISTS_H
#include "gameProcessor/unit.h"

class HumanColonists:  public Unit
{
public:
    HumanColonists(int iterSecX, int iterSecY, int tarSecX, int trSecY, int colonists);
    void process();

protected:
    int m_stX, m_stY;
    int m_tgX, m_tgY;
};

#endif // HUMANCOLONISTS_H
