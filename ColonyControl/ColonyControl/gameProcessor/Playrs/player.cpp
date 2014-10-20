#include "player.h"

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
    m_colonizeTargets.push_back(settlement);
}
