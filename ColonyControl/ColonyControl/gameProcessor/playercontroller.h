#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include "Players/player.h"

#ifdef WIN32
#include "../enums/gameProcessingSettings.h"
#include "../icontroller.h"
#else
#include "enums/gameProcessingSettings.h"
#endif


class PlayerController : public IController
{
public:

    static PlayerController* getInstance();
    Player* getPlayer(int playerID);
    int addNewPlayer(int Race);
	virtual Message* ReseveMessage(Message* message);

protected:
    PlayerController();
    static PlayerController* m_instance;
    int m_playerCounter;

    Player* m_players[NUMBER_OF_PLAYERS];
};

#endif // PLAYERCONTROLLER_H
