#include "module.h"

Module::Module()
{
    for (int ml = MLEVEL_0; ml < NUM_LEVELS; ml++)
    {
        objects[(ModuleObjLevel)ml] = new map<int,GObject*>();
    }
}
