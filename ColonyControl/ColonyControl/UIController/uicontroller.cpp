#include "uicontroller.h"

#include "UIBars/infobar.h"

UIController* UIController::m_instance = new UIController();

UIController::UIController()
{
    //events settings
    m_timeGuard = TimeGuard::getInstance();
    m_currTimeStep = 0;
    int timePoint;
    int step = SEC1 / UI_BAR_UPDATE_RATE;
    for (int i = 0; i < UI_BAR_UPDATE_RATE; i++)
    {
        timePoint = i * step;
        m_eventIDs[i] = m_timeGuard->addEvent(timePoint);
    }
}

void UIController::Init()
{
    InfoBar* infoBar = new InfoBar();
    m_uiBars[t_HumanInfoBar] = infoBar;
}

UIController* UIController::getInstance()
{
    return m_instance;
}

map<ObjectsType, UIBar*>& UIController::getBars()
{
    return m_uiBars;
}


void UIController::process()
{
    int evID = m_eventIDs[m_currTimeStep];
    if (!m_timeGuard->checkEvent(evID, true))
        return;

    m_currTimeStep++;
    if (m_currTimeStep >= UI_BAR_UPDATE_RATE)
        m_currTimeStep = 0;

    InfoBar* infoBar = static_cast<InfoBar*>(m_uiBars[t_HumanInfoBar]);
    infoBar->UpdateInfo();
}
