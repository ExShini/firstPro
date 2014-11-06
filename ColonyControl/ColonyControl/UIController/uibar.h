#ifndef UIBAR_H
#define UIBAR_H
#include "vector"

#include "uielement.h"

using namespace std;

class UIBar: public UIElement
{
public:
    vector<UIElement*>* getElements();


protected:
    UIBar();
    vector<UIElement*> m_elements;
};

#endif // UIBAR_H
