#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H
#include "list"
#include "vector"


#include "planetmap.h"


#ifdef WIN32
#include "../../randomgen.h"
#include "../../objectController/gobject.h"
#include "../../enums/mapGeneratorSattings.h"
#else
#include "randomgen.h"
#include "objectController/gobject.h"
#include "enums/mapGeneratorSattings.h"
#endif

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


    void GenerateMounts(PlanetMap* plMap);
    void GenerateLakes(PlanetMap* plMap);

};

#endif // MAPGENERATOR_H
