#include "timeguard.h"
#include "iostream"

TimeGuard* TimeGuard::m_instance = new TimeGuard();

//debug members
static int secCount = 0;
static int curcount = 0;


/*************************************
FUNC: TimeGuard()
DESC: constructor
*************************************/
TimeGuard::TimeGuard()
{
    m_eventList = new vector<TimeEvent*>();
}

/*************************************
FUNC: ~TimeGuard()
DESC: destructor
*************************************/
TimeGuard::~TimeGuard()
{
    m_eventList->clear();
    delete m_eventList;
}

/*************************************
FUNC: getInstance()
DESC: return TimeGuard instance
*************************************/
TimeGuard* TimeGuard::getInstance()
{
    return m_instance;
}

/*************************************
FUNC: start()
DESC: Start time counting
*************************************/
void TimeGuard::start()
{
    m_lastTime = SDL_GetTicks();
}

/*************************************
FUNC: addEvent()
DESC: This func add new TimeEvent to hendling and return event id
*************************************/
int TimeGuard::addEvent(Uint32 timePoint)
{
    TimeEvent* ev = new TimeEvent(timePoint);
    m_eventList->push_back(ev);
    return m_eventList->size() - 1;
}

/*************************************
FUNC: checkEvent()
DESC: Check event with eventID and return true if time of this event has come
*************************************/
bool TimeGuard::checkEvent(int eventID, bool realizeEv)
{
    TimeEvent* ev = (*m_eventList)[eventID];
    //check status
    if (ev->state == READY)
    {
        if(realizeEv)
            ev->state = COMPLITE;

        return true;
    }
    //else - return false
    return false;
}

/*************************************
FUNC: checkTime()
DESC: Check all events from evenList and set status for each
*************************************/
void TimeGuard::checkTime()
{
    curcount++;
    Uint32 currentTime = SDL_GetTicks();
    Uint32 timeDiff = currentTime - m_lastTime;

    for (Uint32 i = 0; i < m_eventList->size(); i++)
    {
        TimeEvent* ev = (*m_eventList)[i];

        //if event not happen - check time for it
        if (ev->state == NOT_READY)
        {
            if (ev->timePoint < timeDiff)
                ev->state = READY;
        }
    }

    if(timeDiff > SEC1)
    {
        resetEventSatus();
        m_lastTime += SEC1;
    }
}


/*************************************
FUNC: resetEventSatus()
DESC: Reset status for all complite events
*************************************/
void TimeGuard::resetEventSatus()
{
    //debug
    secCount++;
    cout << "TimeGuard " << secCount << "sec. FPS: " << curcount << endl;
    curcount = 0;


    for (Uint32 i = 0; i < m_eventList->size(); i++)
    {
        TimeEvent* ev = (*m_eventList)[i];

        //if event was complete - reset status for next game loop
        if (ev->state == COMPLITE)
        {
            ev->state = NOT_READY;
        }
    }
}

/*************************************
FUNC: realizeEvent()
DESC: set event status with current eventID to COMPLITE
*************************************/
void TimeGuard::realizeEvent(int eventID)
{
    TimeEvent* ev = (*m_eventList)[eventID];
    ev->state = COMPLITE;
}
