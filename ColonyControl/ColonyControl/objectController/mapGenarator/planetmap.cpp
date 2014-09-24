#include "planetmap.h"

PlanetMap::PlanetMap()
{
    for (int ml = MLEVEL_0; ml < NUM_LEVELS; ml++)
    {
        objects[ml] = new Layer();
    }
}
