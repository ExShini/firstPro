#ifndef UICONTROLLER_H
#define UICONTROLLER_H
#include "vector"

#include "uielement.h"
#include "uibar.h"

using namespace std;

class UIController
{
public:
    static UIController* getInstance();
    vector<UIElement *> &getUIElements();

protected:
    UIController();
    UIController(const UIController& other);

    static UIController* m_instance;
    vector<UIElement*> m_uiElementsForDrowing;
    vector<UIBar*> m_uiBars;

};

#endif // UICONTROLLER_H
