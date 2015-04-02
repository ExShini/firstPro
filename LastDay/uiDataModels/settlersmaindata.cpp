#include "settlersmaindata.h"

SettlersMainData::SettlersMainData(QObject *parent):
    QObject(parent),
    m_food(0),
    m_med(0)
{
}

void SettlersMainData::changeFood(int val)
{
    m_food = val;
    emit foodChanged();
}

void SettlersMainData::changeMed(int val)
{
    m_med = val;
    emit medChanged();
}
