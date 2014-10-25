#ifndef PLAYER_H
#define PLAYER_H

#ifdef WIN32
#include "../../enums/gameProcessingSettings.h"
#else
#include "enums/gameProcessingSettings.h"
#include "objectController/gobject.h"
#endif

#include "list"
#include "map"

using namespace std;

class Player
{
public:
    Player(int Race = NoRace);

    void addEmigrantsRequest(GObject* settlement);
    void addImmigrantsRequest(GObject* settlement);
    void addColonistTarget(GObject* settlement);

    virtual GObject* getEmigrantsTarget(int x, int y) = 0;
    virtual GObject* getImmigrantsTarget(int x, int y) = 0;

    virtual int getTopInfSettlementLevel(int level) = 0;
    virtual int getLowInfSettlementLevel(int level) = 0;
    virtual int getPopulationLimit(int level) = 0;
    int getRace() { return m_race; }

protected:
    int m_race;
    list<GObject*> m_emigrantsRequests;
    list<GObject*> m_immigrantsRequests;
    map<int, GObject*> m_colonizeTargets;
};

#endif // PLAYER_H
