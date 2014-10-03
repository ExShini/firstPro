#ifndef TIMEEVENT_H
#define TIMEEVENT_H

#ifdef WIN32
#include"SDL.h"
#include "../ColonyControlWin/stdafx.h"
#else
#include"SDL2/SDL.h"
#endif

class TimeEvent
{
public:
    TimeEvent(Uint32 time);
    int state;
    Uint32 timePoint;
};


enum EventStat
{
    NOT_READY = 0,
    READY,
    COMPLITE
};

#endif // TIMEEVENT_H
