#ifndef PLAYER_H
#define PLAYER_H

#ifdef WIN32
#include "../../enums/gameProcessingSettings.h"
#else
#include "enums/gameProcessingSettings.h"
#include "objectController/gobject.h"
#endif

#include "list"

using namespace std;

class Player
{
public:
    Player(int Race = NoRace);

    void addEmigrantsRequest(GObject* settlement);
    void addImmigrantsRequest(GObject* settlement);

    virtual GObject* getEmigrantsTarget(int x, int y) = 0;

protected:
    int m_race;
    list<GObject*> m_emigrantsRequests;
    list<GObject*> m_immigrantsRequests;
    list<GObject*> m_colonizeTargets;
};

#endif // PLAYER_H
