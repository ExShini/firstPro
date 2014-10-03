#ifndef TIMEGUARD_H
#define TIMEGUARD_H
#define SEC1 1000

#ifdef WIN32
#include"SDL.h"
#include "../ColonyControlWin/stdafx.h"
#else
#include"SDL2/SDL.h"
#endif

#include "vector"

#include "timeevent.h"

using namespace std;

class TimeGuard
{
public:
    static TimeGuard* getInstance();
    void start();
    void checkTime();

    int addEvent(Uint32 timePoint);
    bool checkEvent(int eventID, bool realizeEv);
    void realizeEvent(int eventID);

protected:
    TimeGuard();
    ~TimeGuard();

    static TimeGuard* m_instance;
    Uint32 m_lastTime;
    vector<TimeEvent*>* m_eventList;

    void resetEventSatus();
};

#endif // TIMEGUARD_H
