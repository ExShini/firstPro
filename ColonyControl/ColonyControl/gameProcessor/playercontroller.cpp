#include "iostream"

#include "playercontroller.h"
#include "Playrs/humanplayer.h"

using namespace std;

PlayerController* PlayerController::m_instance = new PlayerController();

PlayerController::PlayerController()
{
    m_playerCounter = 0;
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

int PlayerController::addNewPlayer(int Race)
{

    Player* player = NULL;
    int plID = m_playerCounter;

    if(plID >= NUMBER_OF_PLAYERS)
    {
        cout << "PlayerController::addNewPlayer so much players!" << endl;
        return -1;  //error!
    }

    switch (Race) {
    case Human:
        player = new HumanPlayer();
        m_players[plID] = player;
        break;
    default:
        cout << "We try create player with unknown race!" << endl;
        break;
    }

    m_playerCounter++;
    return plID;
}
