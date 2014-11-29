#include "uicontroller.h"

#include "UIBars/infobar.h"

UIController* UIController::m_instance = new UIController();

UIController::UIController()
{
}

void UIController::Init()
{
    InfoBar* infoBar = new InfoBar();
    m_uiBars.push_back(infoBar);
}

UIController::UIController(const UIController &other)
{
}

UIController* UIController::getInstance()
{
    return m_instance;
}

vector<UIBar*>& UIController::getBars()
{
    return m_uiBars;
}
