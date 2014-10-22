#include "iostream"

#include "settlement.h"

#ifdef WIN32
#include "../../enums/gameProcessingSettings.h"
#else
#include "enums/gameProcessingSettings.h"
#endif



using namespace std;

Settlement::Settlement(Sector* sector, int playerID):
    Buildings(sector, playerID)
{
    //init members
    readyToMove = false;
    m_population = 0;
    m_populationBaseLimit = HUMAN_POPULATION_BASE_LIMIT;
    m_food = 0;
    m_minerals = 0;
    m_production = 0;
    m_colonists = 0;
    m_stateCount = 0;
    m_level = 0;

    m_immigrants = 0;
    m_emigrants = 0;


    m_type = t_HumanSettlers;
    m_fcontroller = new FrameController(
                TextureProvider::getInstance()->getTexture(m_type));

    m_fcontroller->setTextureArea(0, 0);

    m_width = 1;
    m_height = 1;

    m_sector = sector;
    m_x = m_sector->getX();
    m_y = m_sector->getY();
}

void Settlement::process()
{
    //food processing
    int produceFood = HUMANS_GROPS(m_population * HUMAN_FOOD_PRODUCING) ;
    if (produceFood > m_sector->getFertility())
        produceFood = m_sector->getFertility();

    m_food += produceFood;

    //infrastructure building
    if(m_level != HUMAN_MAX_LEVEL)
    {
        m_infrastructure += HUMANS_GROPS(m_population);
    }


    //population processing
    int growth = HUMAN_POPULATION_GROWTH(m_population);
    m_population +=  growth; //HUMAN_POPULATION_GROWTH(m_population);

    //check limits and consumptions
    //food
    m_food -= HUMAN_FOOD_CONSUMPTIONS(m_population);
    if(m_food < 0)
    {
        m_population -= HUMAN_HUNGER_DEMAGE(m_food * (-1));
        m_food = 0;
        foodEmigartion();
    }
    else
    {
        //take 25% of population and compair it with food storage
        //if food storege will be smoll - emigrate
        int pop25 = m_population >> 4;
        if(pop25 > m_food)
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

    m_stateCount++;
    if(m_stateCount >= 5)
    {
        checkState();
    }
}

void Settlement::foodEmigartion()
{

}

void Settlement::popLimitEmigration()
{

}

void Settlement::checkState()
{
    switch (m_level) {
    case 0:
        if(m_population >= 1000)
        {
            m_level++;
            m_fcontroller->setTextureArea(0, 1);
        }
        break;
    case 1:
        if(m_population >= 2000)
        {
            m_level++;
            m_fcontroller->setTextureArea(0, 2);
        }
        else if (m_population < 1000)
        {
            m_level--;
            m_fcontroller->setTextureArea(0, 0);
        }
        break;
    case 2:
        if(m_population >= 3000)
        {
            m_level++;
            m_fcontroller->setTextureArea(0, 3);
        }
        else if (m_population < 2000)
        {
            m_level--;
            m_fcontroller->setTextureArea(0, 1);
        }
        break;
    case 3:
        if(m_population >= 4000)
        {
            m_level++;
            m_fcontroller->setTextureArea(0, 4);
        }
        else if (m_population < 3000)
        {
            m_level--;
            m_fcontroller->setTextureArea(0, 2);
        }
        break;
    case 4:
        if(m_population >= 5000)
        {
            m_level++;
            m_fcontroller->setTextureArea(0, 5);
        }
        else if (m_population < 4000)
        {
            m_level--;
            m_fcontroller->setTextureArea(0, 3);
        }
        break;
    default:
        break;
    }

    m_stateCount = 0;
}

int Settlement::sendColonists()
{
    m_population -= m_colonists;
    int var = m_colonists;

    m_colonists = 0;
    m_moveDesire = 0;
    readyToMove = false;

    return var;
}

void Settlement::inviteColonists(int colonists)
{
    m_population += colonists;
}
