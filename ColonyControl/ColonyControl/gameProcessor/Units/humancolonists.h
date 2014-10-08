#ifndef HUMANCOLONISTS_H
#define HUMANCOLONISTS_H

#ifdef WIN32
#include "../unit.h"
#else
#include "gameProcessor/unit.h"
#endif



class HumanColonists:  public Unit
{
public:
    HumanColonists(int startSecX, int startSecY, int tarSecX, int tarSecY, int colonists);
    void process();

protected:
    int m_stX, m_stY;
    int m_tgX, m_tgY;

    int m_xSpeed, m_ySpeed;
    int m_steps;
    int m_colonists;
};

#endif // HUMANCOLONISTS_H
