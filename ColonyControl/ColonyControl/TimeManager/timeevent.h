#ifndef TIMEEVENT_H
#define TIMEEVENT_H
#include"SDL2/SDL.h"

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
