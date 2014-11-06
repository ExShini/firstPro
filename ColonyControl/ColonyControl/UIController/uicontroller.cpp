#include "uicontroller.h"

UIController* UIController::m_instance = new UIController();

UIController::UIController()
{
}

UIController::UIController(const UIController &other)
{
}

UIController* UIController::getInstance()
{
    return m_instance;
}

vector<UIElement*>& UIController::getUIElements()
{
    return m_uiElementsForDrowing;
}
