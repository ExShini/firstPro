#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "Playrs/player.h"

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
    Player* addNewPlayer(int Race);

protected:
    PlayerController();
    static PlayerController* m_instance;

    Player* m_players[NUMBER_OF_PLAYERS];
};

#endif // PLAYERCONTROLLER_H
