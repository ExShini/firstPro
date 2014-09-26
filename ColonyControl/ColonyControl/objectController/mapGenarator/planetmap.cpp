#include "planetmap.h"

PlanetMap::PlanetMap()
{
    for (int ml = SECTOR_LEVEL; ml < NUM_LEVELS; ml++)
    {
        objects[ml] = new Layer();
    }
}
