#ifndef UILABEL_H
#define UILABEL_H

#include "iostream"
#include "vector"
#include "string"

#ifdef WIN32
#include "../../../objectController/gobject.h"
#else
#include "objectController/gobject.h"
#endif


class UILabel: public GObject
{
public:
    UILabel();

    bool setDataTo(unsigned int position, string &text);
    bool setDataTo(unsigned int position, int number);

    void addData(string & text);
    void addData(int number);

    void applyChanges();

    void clearLabel();

protected:
    vector<string> m_labelText;
};

#endif // UILABEL_H
