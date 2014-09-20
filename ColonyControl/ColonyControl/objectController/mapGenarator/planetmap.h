#ifndef PLANETMAP_H
#define PLANETMAP_H
#include "map"

#include "objectController/gobject.h"

class PlanetMap
{
public:
    PlanetMap();
    map<int,GObject*>* objects[NUM_LEVELS];
};

#endif // PLANETMAP_H
