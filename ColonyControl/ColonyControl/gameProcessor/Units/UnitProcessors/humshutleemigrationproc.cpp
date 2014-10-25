#include "iostream"
#include "humshutleemigrationproc.h"

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

HumShutleEmigrationProc::HumShutleEmigrationProc(Unit* unit):
    UnitProcessor(unit)
{
}


void HumShutleEmigrationProc::process()
{
    HumanColonists* shutle = (HumanColonists*)m_unit;

    if(shutle->getSteps() > 0)
        return;

    shutle->setX(shutle->getTX() MULTIPLY_FS);
    shutle->setY(shutle->getTY() MULTIPLY_FS);

    int currSecX = shutle->getTX();
    int currSecY = shutle->getTY();

    int colonists = shutle->getColonists();
    int playerID = shutle->getPlayerID();

    colonists += GameProcessor::getInstance()->tryGetColonists(currSecX, currSecY,
                                                               HUM_SHITL_COLONISTS_CAPACITY - colonists,
                                                               playerID);
    shutle->setColonists(colonists);

    if(colonists >= HUM_SHITL_COLONISTS_CAPACITY - HUM_SHUTL_COLONISTS_ADMISSION)
    {
        findTagertImmgrateColonists();
    }
    else
    {
        GObject* target = PlayerController::getInstance()->getPlayer(playerID)->getEmigrantsTarget(currSecX, currSecY);

        if(target != NULL)
        {
            shutle->setDirection(target);
        }
        else
        {
            findTagertImmgrateColonists();
        }
    }
}



void HumShutleEmigrationProc::findTagertImmgrateColonists()
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
