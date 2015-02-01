#include "iostream"
#include "humshutleimmigrateproc.h"

#ifdef WIN32
#include "../../../enums/Units/humanUnits.h"
#include "../../../enums/gui_enums.h"
#include "../humancolonists.h"
#include "../../../gameProcessor/playercontroller.h"
#else
#include "enums/Units/humanUnits.h"
#include "enums/gui_enums.h"
#include "gameProcessor/Units/humancolonists.h"
#include "gameProcessor/playercontroller.h"
#endif

using namespace std;

HumShutleImmigrateProc::HumShutleImmigrateProc(Unit* unit):
    UnitProcessor(unit)
{
}

void HumShutleImmigrateProc::process()
{
    HumanColonists* Shuttle = (HumanColonists*)m_unit;

    if(Shuttle->getSteps() > 0)
        return;

    Shuttle->setX(Shuttle->getTX() MULTIPLY_FS);
    Shuttle->setY(Shuttle->getTY() MULTIPLY_FS);

    int tarSecX = Shuttle->getTX();
    int tarSecY = Shuttle->getTY();
    int colonists = Shuttle->getColonists();

    //colonize target sector
    bool success = GameProcessor::getInstance()->tryColonize(tarSecX, tarSecY, colonists, Shuttle->getPlayerID());

    if (!success)
    {
        findTagertImmgrateColonists();
    }
    else
    {
        Shuttle->setColonists(0);
        GObject* target = PlayerController::getInstance()->getPlayer(Shuttle->getPlayerID())
                ->getEmigrantsTarget(Shuttle->getTX(), Shuttle->getTY());

        if (target != NULL)
        {
            Shuttle->setStatuse(findEmigrants);
            Shuttle->setDirection(target);
        }
        else
        {
            Shuttle->setStatuse(returnToBase);
            Shuttle->setDirection(Shuttle->getBase());
        }
    }
}


void HumShutleImmigrateProc::findTagertImmgrateColonists()
{
    HumanColonists* Shuttle = (HumanColonists*)m_unit;
    GObject* target = PlayerController::getInstance()->getPlayer(Shuttle->getPlayerID())
            ->getImmigrantsTarget(Shuttle->getTX(), Shuttle->getTY());

    if(target != NULL)
    {
        Shuttle->setStatuse(moveImmigrants);
        Shuttle->setDirection(target);
    }
    else
    {
        Shuttle->setStatuse(returnToBase);
        Shuttle->setDirection(Shuttle->getBase());
    }
}

