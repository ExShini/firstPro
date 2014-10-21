#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "player.h"

class HumanPlayer : public Player
{
public:
    HumanPlayer();

    GObject* getEmigrantsTarget(int x, int y);
    GObject* getImmigrantsTarget(int x, int y);

protected:
    GObject* colonizeNewArea(int x, int y);
    GObject* resettleColonists(int x, int y);

    GObject* getTargetFromList(int x, int y, list<GObject*> source, int range);

};

#endif // HUMANPLAYER_H
