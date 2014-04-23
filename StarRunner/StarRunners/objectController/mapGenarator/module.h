#ifndef MODULE_H
#define MODULE_H
#include "map"

#include "objectController/gobject.h"

class Module
{
public:
    Module();
    map<int,GObject*>* objects[NUM_LEVELS];
};
#endif // MODULE_H
