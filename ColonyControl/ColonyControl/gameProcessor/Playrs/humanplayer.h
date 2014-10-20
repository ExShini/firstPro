#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "player.h"

class HumanPlayer : public Player
{
public:
    HumanPlayer();

    GObject* getEmigrantsTarget(int x, int y);
};

#endif // HUMANPLAYER_H
