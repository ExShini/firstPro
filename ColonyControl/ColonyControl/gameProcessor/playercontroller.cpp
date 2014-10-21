#include "iostream"

#include "playercontroller.h"
#include "Playrs/humanplayer.h"

using namespace std;

PlayerController* PlayerController::m_instance = new PlayerController();

PlayerController::PlayerController()
{
    for(int i = 0; i < NUMBER_OF_PLAYERS; i++)
    {
        m_players[i] = NULL;
    }
}

PlayerController* PlayerController::getInstance()
{
    return m_instance;
}

Player* PlayerController::getPlayer(int playerID)
{
    Player* player = NULL;

    if(playerID < NUMBER_OF_PLAYERS)
    {
        player = m_players[playerID];
    }

    return player;
}

Player* PlayerController::addNewPlayer(int Race)
{
    Player* player = NULL;

    switch (Race) {
    case Human:
       player = new HumanPlayer();
        break;
    default:
        cout << "We try create player with unknown race!" << endl;
        break;
    }

    return player;
}
