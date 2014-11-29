#include "iostream"

#include "settlement.h"

#ifdef WIN32
#include "../../../enums/gameProcessingSettings.h"
#include "../../../gameProcessor/playercontroller.h"
#include "../../../gameProcessor/gameprocessor.h"
#else
#include "enums/gameProcessingSettings.h"
#include "gameProcessor/playercontroller.h"
#include "gameProcessor/gameprocessor.h"
#endif

using namespace std;


/*************************************
FUNC: Settlement(Sector* sector, int playerID)
DESC: Constructor
*************************************/
Settlement::Settlement(Sector* sector, int playerID):
    Buildings(sector, playerID)
{
    //init members
    m_readyToMove = false;
    m_population = 0;
    m_food = 0;
    m_minerals = 0;
    m_production = 0;
    m_colonists = 0;
    m_stateCount = 0;
    m_level = 0;

    m_immigrants = 0;
    m_emigrants = 0;
    m_moveDesire = 0;
    m_infrastructure = 0;


    //set default values for limits
    Player* pl = PlayerController::getInstance()->getPlayer(playerID);

    m_lowInfLevel = 0;
    m_topInfLevel = pl->getTopInfSettlementLevel(0);
    m_populationLimit = pl->getPopulationLimit(0);

    m_type = t_HumanSettlers;
    m_fcontroller = new FrameController(
                TextureProvider::getInstance()->getTexture(m_type));

    m_fcontroller->setTextureArea(0, 0);

    m_width = 1;
    m_height = 1;

    m_sector = sector;
    m_x = m_sector->getX();
    m_y = m_sector->getY();

    GameProcessor::getInstance()->checkEmptyAreas(m_x, m_y, m_playerID);
}

/*************************************
FUNC: process()
DESC: Main process func
*************************************/
void Settlement::process()
{
    //food processing
    int produceFood = HUMANS_GROPS(m_population * HUMAN_FOOD_PRODUCING) ;
    if (produceFood > m_sector->getFertility())
        produceFood = m_sector->getFertility();

    m_food += produceFood;


    //population processing
    int growth = HUMAN_POPULATION_GROWTH(m_population);
    m_population +=  growth; //HUMAN_POPULATION_GROWTH(m_population);

    //reset emigrants
    m_colonists = 0;

    //check limits and consumptions
    //food
    m_food -= HUMAN_FOOD_CONSUMPTIONS(m_population);
    if(m_food < 0)
    {
        m_population -= HUMAN_HUNGER_DEMAGE(0);
        //m_population -= HUMAN_HUNGER_DEMAGE(m_food * (-1));
        foodEmigartion();
        m_food = 0;
    }
    else
    {
        //take 12.5% of population and compair it with food storage
        //if food storege will be smoll - emigrate
        int pop125 = m_population >> 3;
        if(pop125 > m_food)
        {
            foodEmigartion();
        }
    }

    //population
    if(m_population > m_populationLimit)
    {
        int excess = m_population - m_populationLimit;
        m_population -= HUMAN_POPULATION_DEMAGE(excess);
        popLimitEmigration();
    }
    else
    {
        //if population less than 75% of population limit and settlement
        //have enough food - send immigrate request
        int pop75limit = m_populationLimit - (m_populationLimit >> 2);
        if (m_population < pop75limit && m_moveDesire == 0)
        {
            immigrationReq();
        }
    }

    //infrastructure building
    if(m_level != HUMAN_MAX_SETTLEMENT_LEVEL && m_food > 0)
    {
        m_infrastructure += HUMANS_GROPS(m_population);
    }

    m_stateCount++;
    if(m_stateCount >= 5)
    {
        checkState();
    }


}

/*************************************
FUNC: immigrationReq()
DESC: Add immigration request. We need new colonists!
*************************************/
void Settlement::immigrationReq()
{
    Player* pl = PlayerController::getInstance()->getPlayer(m_playerID);
    pl->addImmigrantsRequest(this);
}

/*************************************
FUNC: foodEmigartion()
DESC: Add emigration request (if it needed) and refresh number of colonists
*************************************/
void Settlement::foodEmigartion()
{
    m_moveDesire++;
    //take 12.5% of population and change it by food storage
    m_colonists = (m_population >> 3) - m_food;

    if(m_colonists < 0)
    {
        m_colonists = 0;
        return;
    }

    if(m_moveDesire < MIN_HUMAN_MOVE_DESIE)
        return;

    if(m_readyToMove == false)
    {
        Player* pl = PlayerController::getInstance()->getPlayer(m_playerID);
        pl->addEmigrantsRequest(this);
        m_readyToMove = true;
    }
}

/*************************************
FUNC: popLimitEmigration()
DESC: Add emigration request (if it needed) and increase number of colonists
*************************************/
void Settlement::popLimitEmigration()
{
    m_moveDesire++;
    int col = m_population - m_populationLimit;

    if(m_colonists < col)
    {
        m_colonists = col;
    }

    if(m_colonists < 0)
    {
        m_colonists = 0;
        return;
    }

    if(m_moveDesire < MIN_HUMAN_MOVE_DESIE)
        return;

    if(m_readyToMove == false)
    {
        Player* pl = PlayerController::getInstance()->getPlayer(m_playerID);
        pl->addEmigrantsRequest(this);
        m_readyToMove = true;
    }
}

/*************************************
FUNC: checkState()
DESC: Check settlement state - increase, decrease settlement's level
*************************************/
void Settlement::checkState()
{
    //check top limit
    if (m_level < HUMAN_MAX_SETTLEMENT_LEVEL)
    {
        if(m_infrastructure >= m_topInfLevel)
        {
            m_level++;

            //change setting
            Player* pl = PlayerController::getInstance()->getPlayer(m_playerID);
            m_lowInfLevel = pl->getLowInfSettlementLevel(m_level);
            m_topInfLevel = pl->getTopInfSettlementLevel(m_level);
            m_populationLimit = pl->getPopulationLimit(m_level);
            m_fcontroller->setTextureArea(0, m_level);
        }
    }

    if(m_level > 0)
    {
        if(m_infrastructure < m_lowInfLevel)
        {
            m_level--;

            //change setting
            Player* pl = PlayerController::getInstance()->getPlayer(m_playerID);
            m_lowInfLevel = pl->getLowInfSettlementLevel(m_level);
            m_topInfLevel = pl->getTopInfSettlementLevel(m_level);
            m_populationLimit = pl->getPopulationLimit(m_level);
            m_fcontroller->setTextureArea(0, m_level);
        }
    }

    //reset state count
    m_stateCount = 0;
}

/*************************************
FUNC: sendColonists(int maxColonists)
DESC: Send colonists to shutle
*************************************/
int Settlement::sendColonists(int maxColonists)
{
    int emigrants = 0;

    if(m_colonists > maxColonists)
    {
        emigrants = maxColonists;
    }
    else
    {
        emigrants = m_colonists;
    }

    if(emigrants < (m_population >> 1) )
    {
        m_population -= emigrants;
    }
    else
    {
        emigrants = m_population >> 1;
        m_population -= emigrants;
    }

    m_colonists = 0;
    m_moveDesire = 0;
    m_readyToMove = false;

    return emigrants;
}

/*************************************
FUNC: inviteColonists(int colonists)
DESC: Invite colonist to settlement
*************************************/
void Settlement::inviteColonists(int colonists)
{
    m_population += colonists;
}
