#ifndef UICONTROLLER_H
#define UICONTROLLER_H
#include "vector"

#define UI_BAR_UPDATE_RATE 3

#ifdef WIN32
#include "../TimeManager/timeguard.h"
#else
#include "TimeManager/timeguard.h"
#endif


#include "uibar.h"

using namespace std;

class UIController
{
public:
    static UIController* getInstance();
    void Init();
    void process();

    map<ObjectsType, UIBar *> &getBars();

protected:
    UIController();
    UIController(const UIController& other);

    SDL_Renderer * m_render;

    static UIController* m_instance;
    map<ObjectsType, UIBar*> m_uiBars;


    //timer's members - need for events work
    int m_eventIDs[UI_BAR_UPDATE_RATE];
    TimeGuard* m_timeGuard;
    int m_currTimeStep;

};

#endif // UICONTROLLER_H
