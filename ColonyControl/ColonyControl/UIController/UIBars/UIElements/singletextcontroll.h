#ifndef SINGLETEXTCONTROLL_H
#define SINGLETEXTCONTROLL_H

#include "iostream"
#include "string"

#ifdef WIN32
#include "../../../objectController/gobject.h"
#else
#include "objectController/gobject.h"
#endif

using namespace std;

class SingleTextControll: public GObject
{
public:
    SingleTextControll();
    void setData(int number);
    void setData(string &text);
};

#endif // SINGLETEXTCONTROLL_H
