#include "unitcontroller.h"

UnitController* UnitController::m_instance = new UnitController();

UnitController::UnitController()
{
    m_units = new vector<Unit*>();
}

UnitController* UnitController::getInstance()
{
    return m_instance;
}

void UnitController::addUnit(Unit * unit)
{
    m_units->push_back(unit);
}

void UnitController::process()
{
    for (int i = 0; i < m_units->size(); i++)
    {
        Unit* unit = (*m_units)[i];
        unit->process();
    }
}
