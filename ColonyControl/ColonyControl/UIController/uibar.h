#ifndef UIBAR_H
#define UIBAR_H
#include "vector"

#ifdef WIN32
#include "../gobject.h"
#else
#include "objectController/gobject.h"
#endif


using namespace std;

class UIBar: public GObject
{
public:
    vector<GObject*>& getElements();

protected:
    UIBar();
    vector<GObject*> m_elements;
};

#endif // UIBAR_H
