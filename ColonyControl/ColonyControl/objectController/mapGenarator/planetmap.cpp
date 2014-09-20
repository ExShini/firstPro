#include "planetmap.h"

PlanetMap::PlanetMap()
{
    for (int ml = MLEVEL_0; ml < NUM_LEVELS; ml++)
    {
        objects[(ModuleObjLevel)ml] = new map<int,GObject*>();
    }
}
