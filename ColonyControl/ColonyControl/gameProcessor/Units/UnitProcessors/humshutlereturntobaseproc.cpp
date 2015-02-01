#include "humshutlereturntobaseproc.h"

#ifdef WIN32
#include "../humancolonists.h"
#else
#include "gameProcessor/Units/humancolonists.h"
#include "objectController/objects/humanBuildings/colonycenter.h"
#endif

HumShutleReturnToBaseProc::HumShutleReturnToBaseProc(Unit *unit):
    UnitProcessor(unit)
{
}


void HumShutleReturnToBaseProc::process()
{
    HumanColonists* Shuttle = (HumanColonists*)m_unit;

    if(Shuttle->getSteps() > 0)
        return;


    Shuttle->finishActive();

    GObject* base = Shuttle->getBase();

	if (base == NULL)
		return;

    if(base->getType() == t_HumanColonyCenter)
    {
        ColonyCenter* colonyCenter = (ColonyCenter*)base;
        colonyCenter->returnToBase();
    }
}
