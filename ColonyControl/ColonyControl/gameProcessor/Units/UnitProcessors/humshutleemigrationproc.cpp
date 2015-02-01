#include "iostream"
#include "humshutleemigrationproc.h"

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

HumShutleEmigrationProc::HumShutleEmigrationProc(Unit* unit):
    UnitProcessor(unit)
{
}


void HumShutleEmigrationProc::process()
{
    HumanColonists* Shuttle = (HumanColonists*)m_unit;

    if(Shuttle->getSteps() > 0)
        return;

    Shuttle->setX(Shuttle->getTX() MULTIPLY_FS);
    Shuttle->setY(Shuttle->getTY() MULTIPLY_FS);

    int currSecX = Shuttle->getTX();
    int currSecY = Shuttle->getTY();

    int colonists = Shuttle->getColonists();
    int playerID = Shuttle->getPlayerID();

    colonists += GameProcessor::getInstance()->tryGetColonists(currSecX, currSecY,
                                                               HUM_SHITL_COLONISTS_CAPACITY - colonists,
                                                               playerID);
    Shuttle->setColonists(colonists);

    if(colonists >= HUM_SHITL_COLONISTS_CAPACITY - HUM_SHUTL_COLONISTS_ADMISSION)
    {
        findTagertImmgrateColonists();
    }
    else
    {
        GObject* target = PlayerController::getInstance()->getPlayer(playerID)->getEmigrantsTarget(currSecX, currSecY);

        if(target != NULL)
        {
            Shuttle->setDirection(target);
        }
        else
        {
            findTagertImmgrateColonists();
        }
    }
}



void HumShutleEmigrationProc::findTagertImmgrateColonists()
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
