#include "iostream"
#include "cmath"

#include "humanplayer.h"

#ifdef WIN32
#include "../../randomgen.h"
#include "../../enums/Units/humanUnits.h"
#include "../../enums/gui_enums.h"
#else
#include "randomgen.h"
#include "enums/Units/humanUnits.h"
#include "enums/gui_enums.h"
#endif

using namespace std;

/*************************************
FUNC: HumanPlayer()
DESC: constructor
*************************************/
HumanPlayer::HumanPlayer():
    Player(Human)
{
    //set unfrastructure limits
    m_infrastructureLimits[0] = HUM_INF_LVL_1;
    m_infrastructureLimits[1] = HUM_INF_LVL_2;
    m_infrastructureLimits[2] = HUM_INF_LVL_3;
    m_infrastructureLimits[3] = HUM_INF_LVL_4;
    m_infrastructureLimits[4] = HUM_INF_LVL_5;
    m_infrastructureLimits[5] = HUM_INF_LVL_6;
    m_infrastructureLimits[6] = HUM_INF_LVL_7;
    m_infrastructureLimits[7] = HUM_INF_LVL_8;
    m_infrastructureLimits[8] = HUM_INF_LVL_9;

    //set population limits
    m_populationLimits[0] = HUM_POP_LIM_0;
    m_populationLimits[1] = HUM_POP_LIM_1;
    m_populationLimits[2] = HUM_POP_LIM_2;
    m_populationLimits[3] = HUM_POP_LIM_3;
    m_populationLimits[4] = HUM_POP_LIM_4;
    m_populationLimits[5] = HUM_POP_LIM_5;
    m_populationLimits[6] = HUM_POP_LIM_6;
    m_populationLimits[7] = HUM_POP_LIM_7;
    m_populationLimits[8] = HUM_POP_LIM_8;
    m_populationLimits[9] = HUM_POP_LIM_9;
}

/*************************************
FUNC: getEmigrantsTarget(int x, int y)
DESC: find new emigrants for human Shuttle
*************************************/
GObject* HumanPlayer::getEmigrantsTarget(int x, int y)
{
    cout << "HumanPlayer::getEmigrantsTarget" << endl;
    return getTargetFromList(x, y, m_emigrantsRequests, HUM_SHUTL_TRANSPORT_ACTIVITY_RANGE);
}


/*************************************
FUNC: getTargetFromList(int x, int y, list<GObject *> source, int range)
DESC: find target from current list
*************************************/
GObject* HumanPlayer::getTargetFromList(int x, int y, list<GObject *> &source, int range)
{
    list<GObject*>::iterator iter = source.begin();
    list<GObject*>::iterator end = source.end();

    GObject* targetSec = NULL;
    int tarDis = 999;
    list<GObject*>::iterator tarIter;

    for(;iter != end; iter++)
    {
        GObject* sector = static_cast<GObject*>(*iter);
        int dist = sqrt( pow((sector->getX() - x), 2) + pow((sector->getY() - y), 2) );

        if(dist < range)
        {
            source.erase(iter);
            return sector;
        }
        else
        {
            if (dist < tarDis)
            {
                tarDis = dist;
                targetSec = sector;
                tarIter = iter;
            }
        }
    }
    \
    if(targetSec != NULL)
    {
        source.erase(tarIter);
    }
    return targetSec;
}


/*************************************
FUNC: getTargetFromList(int x, int y, list<GObject *> source, int range)
DESC: find target from current list
*************************************/
GObject* HumanPlayer::getTargetFromMap(int x, int y, map<int, GObject *> &source)
{
    map<int, GObject *>::iterator iter = source.begin();
    map<int, GObject *>::iterator end = source.end();

    map<int, GObject*> candidates;

    int tarDis = 999;

    for(;iter != end; iter++)
    {
        GObject* sector = static_cast<GObject*>((*iter).second);
        int key = (*iter).first;

        int dist = sqrt( pow((sector->getX() - x), 2) + pow((sector->getY() - y), 2) );

        if (dist < tarDis)
        {
            candidates.clear();

            candidates[key] = sector;
            tarDis = dist;
        }
        else if(dist == tarDis)
        {
            candidates[key] = sector;
        }

    }

    GObject* targetSec = NULL;

    int candSize = candidates.size();
    if(candSize != 0)
    {
        int posit = RandomGen::getRand() % candidates.size();
        int count = 0;
        int targetKey = -1;

        iter = candidates.begin();
        end = candidates.end();

        for(; iter != end ; iter++)
        {
            if(count == posit)
            {
                targetSec = (*iter).second;
                targetKey = (*iter).first;
            }

            count++;
        }

        source.erase(targetKey);
    }




    return targetSec;
}

/*************************************
FUNC: getImmigrantsTarget(int x, int y)
DESC: choose target for human-colonists Shuttle
*************************************/
GObject* HumanPlayer::getImmigrantsTarget(int x, int y)
{
    int immigranstCount = m_immigrantsRequests.size();
    int colTargets = m_colonizeTargets.size() + immigranstCount;

    if (colTargets > 0)
    {

        if(immigranstCount > 0)
        {
            //try choose target for colonists
            int emigrantsCount = m_emigrantsRequests.size() + 2;
            int randBorder = emigrantsCount + immigranstCount;

            short rand = RandomGen::getRand() % randBorder;

            if (rand > immigranstCount)
            {
                return colonizeNewArea(x,y);
            }
            else
            {
                return resettleColonists(x,y);
            }
        }
        else
        {
            return colonizeNewArea(x,y);
        }
    }

    return resettleColonists(x,y);
}

/*************************************
FUNC: colonizeNewArea(int x, int y)
DESC: find new area for colonists
*************************************/
GObject* HumanPlayer::colonizeNewArea(int x, int y)
{
    return getTargetFromMap(x, y, m_colonizeTargets);
}



/*************************************
FUNC: resettleColonists(int x, int y)
DESC: find settlements for colonists
*************************************/
GObject* HumanPlayer::resettleColonists(int x, int y)
{
    return getTargetFromList(x, y, m_immigrantsRequests, HUM_SHUTL_TRANSPORT_ACTIVITY_RANGE);
}

/*************************************
FUNC: getTopInfSettlementLevel(int level)
DESC: return top infrastructure limit for current settlement level
*************************************/
int HumanPlayer::getTopInfSettlementLevel(int level)
{
    if (level < HUMAN_MAX_SETTLEMENT_LEVEL)
        return m_infrastructureLimits[level];
    else
        return 0;
}

/*************************************
FUNC: getLowInfSettlementLevel(int level)
DESC: return low infrastructure limit for current settlement level
*************************************/
int HumanPlayer::getLowInfSettlementLevel(int level)
{
    if (level > 0)
        return m_infrastructureLimits[level - 1];
    else
        return 0;
}

/*************************************
FUNC: getPopulationLimit(int level)
DESC: return population limit for current settlement level
*************************************/
int HumanPlayer::getPopulationLimit(int level)
{
    return m_populationLimits[level];
}
