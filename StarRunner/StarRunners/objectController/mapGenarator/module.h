#ifndef MODULE_H
#define MODULE_H
#include "map"

#include "objectController/gobject.h"

class Module
{
public:
    Module();

    map<int,GObject*>* externalLevel;
    map<int,GObject*>* middleLevel;
    map<int,GObject*>* topLevel;
};

#endif // MODULE_H
