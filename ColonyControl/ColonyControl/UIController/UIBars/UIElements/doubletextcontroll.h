#ifndef DOUBLETEXTCONTROLL_H
#define DOUBLETEXTCONTROLL_H

#include "iostream"
#include "string"

#ifdef WIN32
#include "../../../objectController/gobject.h"
#else
#include "objectController/gobject.h"
#endif


class DoubleTextControll: public GObject
{
public:
    DoubleTextControll();

    void setFirstData(int number);
    void setFirstData(string &text);

    void setSecondData(int number);
    void setSecondData(string &text);

    void setSeparator(string & sep);

    void ApplyChange();

protected:
    string m_first;
    string m_second;
    string m_sep;
};

#endif // DOUBLETEXTCONTROLL_H
