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
    HumanColonists* shutle = (HumanColonists*)m_unit;

    if(shutle->getSteps() > 0)
        return;


    shutle->finishActive();

    GObject* base = shutle->getBase();

	if (base == NULL)
		return;

    if(base->getType() == t_HumanColonyCenter)
    {
        ColonyCenter* colonyCenter = (ColonyCenter*)base;
        colonyCenter->returnToBase();
    }
}
