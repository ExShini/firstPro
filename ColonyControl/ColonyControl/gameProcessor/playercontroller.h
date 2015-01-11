#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "Players/player.h"

#ifdef WIN32
#include "../enums/gameProcessingSettings.h"
#else
#include "enums/gameProcessingSettings.h"
#endif


class PlayerController
{
public:

    static PlayerController* getInstance();
    Player* getPlayer(int playerID);
    int addNewPlayer(int Race);

protected:
    PlayerController();
    static PlayerController* m_instance;
    int m_playerCounter;

    Player* m_players[NUMBER_OF_PLAYERS];
};

#endif // PLAYERCONTROLLER_H
