#include "iostream"
#include "humshutleimmigrateproc.h"

#ifdef WIN32
#include "../../../enums/Units/humanUnits.h"
#include "../../enums/gui_enums.h"
#include "../humancolonists.h"
#include "../../gameProcessor/playercontroller.h"
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
    HumanColonists* shutle = (HumanColonists*)m_unit;

    if(shutle->getSteps() > 0)
        return;

    shutle->setX(shutle->getTX() MULTIPLY_FS);
    shutle->setY(shutle->getTY() MULTIPLY_FS);

    int tarSecX = shutle->getTX();
    int tarSecY = shutle->getTY();
    int colonists = shutle->getColonists();

    //colonize target sector
    bool success = GameProcessor::getInstance()->tryColonize(tarSecX, tarSecY, colonists, shutle->getPlayerID());

    if (!success)
    {
        findTagertImmgrateColonists();
    }
    else
    {
        shutle->setColonists(0);
        GObject* target = PlayerController::getInstance()->getPlayer(shutle->getPlayerID())
                ->getEmigrantsTarget(shutle->getTX(), shutle->getTY());

        if (target != NULL)
        {
            shutle->setStatuse(findEmigrants);
            shutle->setDirection(target);
        }
        else
        {
            shutle->setStatuse(returnToBase);
            shutle->setDirection(shutle->getBase());
        }
    }
}


void HumShutleImmigrateProc::findTagertImmgrateColonists()
{
    HumanColonists* shutle = (HumanColonists*)m_unit;
    GObject* target = PlayerController::getInstance()->getPlayer(shutle->getPlayerID())
            ->getImmigrantsTarget(shutle->getTX(), shutle->getTY());

    if(target != NULL)
    {
        shutle->setStatuse(moveImmigrants);
        shutle->setDirection(target);
    }
    else
    {
        shutle->setStatuse(returnToBase);
        shutle->setDirection(shutle->getBase());
    }
}

