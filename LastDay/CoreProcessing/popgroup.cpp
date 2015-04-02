#include <QDebug>
#include "popgroup.h"

PopGroup::PopGroup():
    m_free(0),
    m_active(0),
    m_notActive(0),
    m_max(0)
{
}

void PopGroup::sendUpdate()
{
    emit popChanged(m_free, m_active, m_notActive, m_max);
}

void PopGroup::takeDamage(int kill, int damaged, GROUP group)
{
    switch (group)
    {
    case HOME:
        m_free -= kill;
        m_free -= damaged;
        m_notActive += damaged;
        break;

    case MISS:
        m_active -= kill;
        m_active -= damaged;
        m_notActive += damaged;
        break;

    case HOSP:
        m_active -= kill;
        m_active -= damaged;
        break;

    default:
        qDebug() << "!!! ERORR! PopGroup::takeDamage - unknown type of GROUP";
        break;
    }
}

void PopGroup::sendToWork(int workers)
{
    m_free -= workers;
    m_active += workers;
}

void PopGroup::cured(int pop)
{
    m_notActive -= pop;
    m_free += pop;
}

void PopGroup::freed(int freedWorkers)
{
    m_active -= freedWorkers;
    m_free += freedWorkers;
}
