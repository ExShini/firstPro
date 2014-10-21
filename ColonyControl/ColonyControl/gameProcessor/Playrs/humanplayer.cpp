#include "humanplayer.h"

#ifdef WIN32
#include "../../randomgen.h"
#include "../../enums/Units/humanUnits.h"
#else
#include "randomgen.h"
#include "enums/Units/humanUnits.h"
#endif

#include "cmath"

/*************************************
FUNC: HumanPlayer()
DESC: constructor
*************************************/
HumanPlayer::HumanPlayer():
    Player(Human)
{

}

/*************************************
FUNC: getEmigrantsTarget(int x, int y)
DESC: find new emigrants for human shutle
*************************************/
GObject* HumanPlayer::getEmigrantsTarget(int x, int y)
{
    return getTargetFromList(x, y, m_emigrantsRequests, HUM_SHUTL_TRANSPORT_ACTIVITY_RANGE);
}


/*************************************
FUNC: getTargetFromList(int x, int y, list<GObject *> source, int range)
DESC: find target from current list
*************************************/
GObject* HumanPlayer::getTargetFromList(int x, int y, list<GObject *> source, int range)
{
    list<GObject*>::iterator iter = source.begin();
    list<GObject*>::iterator end = source.end();

    GObject* targetSec = NULL;
    int tarDis = 999;
    list<GObject*>::iterator tarIter;

    for(;iter != end; iter++)
    {
        GObject* sector = *iter;
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
    source.erase(tarIter);
    return targetSec;
}

/*************************************
FUNC: getImmigrantsTarget(int x, int y)
DESC: choose target for human-colonists shutle
*************************************/
GObject* HumanPlayer::getImmigrantsTarget(int x, int y)
{
    int colTargets = m_colonizeTargets.size();
    if (colTargets > 0)
    {
        //try choose target for colonists
        short emigrantsCount = m_emigrantsRequests.size();
        short immigranstCount = m_immigrantsRequests.size();

        int randBorder = emigrantsCount + immigranstCount;

        if(randBorder > 0)
        {
            short rand = RandomGen::getRand();
            if (rand > immigranstCount)
            {
                return colonizeNewArea(x,y);
            }
            else
            {
                return resettleColonists(x,y);
            }
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
    return getTargetFromList(x, y, m_colonizeTargets, HUM_SHUTL_TRANSPORT_ACTIVITY_RANGE);
}



/*************************************
FUNC: resettleColonists(int x, int y)
DESC: find settlements for colonists
*************************************/
GObject* HumanPlayer::resettleColonists(int x, int y)
{
    return getTargetFromList(x, y, m_immigrantsRequests, HUM_SHUTL_TRANSPORT_ACTIVITY_RANGE);
}
