#include "module.h"

Module::Module()
{
    externalLevel = new map<int,GObject*>();
    middleLevel = map<int,GObject*>();
    topLevel = map<int,GObject*>();
}
