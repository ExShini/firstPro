#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "player.h"

class HumanPlayer : public Player
{
public:
    HumanPlayer();

    GObject* getEmigrantsTarget(int x, int y);
    GObject* getImmigrantsTarget(int x, int y);

    int getTopInfSettlementLevel(int level);
    int getLowInfSettlementLevel(int level);
    int getPopulationLimit(int level);

protected:
    GObject* colonizeNewArea(int x, int y);
    GObject* resettleColonists(int x, int y);

    GObject* getTargetFromList(int x, int y, list<GObject*> source, int range);

    int m_infrastructureLimits[HUMAN_MAX_SETTLEMENT_LEVEL];
    int m_populationLimits[HUMAN_MAX_SETTLEMENT_LEVEL + 1];

};

#endif // HUMANPLAYER_H
