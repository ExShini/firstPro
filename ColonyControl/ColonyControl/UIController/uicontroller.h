#ifndef UICONTROLLER_H
#define UICONTROLLER_H
#include "vector"

#include "uibar.h"

using namespace std;

class UIController
{
public:
    static UIController* getInstance();
    void Init();
    vector<UIBar*> &getBars();

protected:
    UIController();
    UIController(const UIController& other);

    static UIController* m_instance;
    vector<UIBar*> m_uiBars;

};

#endif // UICONTROLLER_H
