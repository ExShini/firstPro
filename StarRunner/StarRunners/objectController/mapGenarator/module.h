#ifndef MODULE_H
#define MODULE_H
#include "map"

#include "objectController/gobject.h"

class module
{
public:
    module();

    map<int,GObject*>* externalLevel;
    map<int,GObject*>* middleLevel;
    map<int,GObject*>* topLevel;
};

#endif // MODULE_H
