#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H
#include "list"
#include "vector"

#include "randomgen.h"
#include "objectController/gobject.h"
#include "planetmap.h"
#include "enums/mapGeneratorSattings.h"


class MapGenerator
{

public:
    MapGenerator();
    ~MapGenerator();
    PlanetMap *generateMap(PlanetType planetType);

protected:

    int getCostByType(ObjectsType type);
    GObject* getGObjectByType(ObjectsType type, Direction dir);

    RandomGen* m_randGen;

};

#endif // MAPGENERATOR_H
