#include "player.h"

Player::Player(int Race):
    m_race(Race)
{
}


Player::addEmigrantsRequest(GObject *settlement)
{
    m_emigrantsRequests.push_back(settlement);
}

Player::addImmigrantsRequest(GObject *settlement)
{
    m_immigrantsRequests.push_back(settlement);
}
