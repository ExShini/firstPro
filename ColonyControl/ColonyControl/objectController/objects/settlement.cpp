#include "iostream"

#include "settlement.h"

#ifdef WIN32
#include "../../enums/gameProcessingSettings.h"
#else
#include "enums/gameProcessingSettings.h"
#endif



using namespace std;

Settlement::Settlement(Sector* sector):
    readyToMove(false),
    m_population(0),
    m_populationBaseLimit(HUMAN_POPULATION_BASE_LIMIT),
    m_food(0),
    m_minerals(0),
    m_production(0),
    m_colonists(0)

{
    m_type = t_HumanSettlers;
    m_fcontroller = new FrameController(
                TextureProvider::getInstance()->getTexture(m_type));

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


    m_colonists += HUMAN_COLONIST(m_population);
    m_moveDesire++;

    if (m_moveDesire >= HUMAN_RATE_OF_MOVING && HUMANS_GROPS(m_colonists) > 0)
        readyToMove = true;

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
    }

    //population
    if(m_population > HUMAN_POPULATION_BASE_LIMIT)
    {
        int excess = m_population - HUMAN_POPULATION_BASE_LIMIT;
        m_population -= HUMAN_POPULATION_DEMAGE(excess);
    }

    /*
    cout << "Sector "<< m_x << ":" << m_y << " \tPopulation: " << m_population << "+" << growth
         << " \tFood: " << m_food << " +" << produceFood << endl;
    */
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
