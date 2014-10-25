#include "iostream"

#include "player.h"

#ifdef WIN32
#else
#include "enums/gui_enums.h"
#endif

using namespace std;

/*************************************
FUNC: Player()
DESC: constructor
*************************************/
Player::Player(int Race):
    m_race(Race)
{
}


/*************************************
FUNC: addEmigrantsRequest(GObject *settlement)
DESC: add new emigration reques
*************************************/
void Player::addEmigrantsRequest(GObject *settlement)
{
    m_emigrantsRequests.push_back(settlement);
}

/*************************************
FUNC: addImmigrantsRequest(GObject *settlement)
DESC: add new immigration reques
*************************************/
void Player::addImmigrantsRequest(GObject *settlement)
{
    m_immigrantsRequests.push_back(settlement);
}

/*************************************
FUNC: addColonistTarget(GObject *settlement)
DESC: add new sector for colony targets
*************************************/
void Player::addColonistTarget(GObject *settlement)
{
    int key = (settlement->getX() MULTIPLY_FS) + settlement->getY();
    if(m_colonizeTargets.find(key) == m_colonizeTargets.end())
    {
        m_colonizeTargets[key] = settlement;
    }
}
