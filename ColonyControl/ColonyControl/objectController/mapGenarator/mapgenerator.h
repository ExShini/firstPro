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


    void GenerateFertility(PlanetMap* plMap);
    void GenerateMinerals(PlanetMap* plMap);
    void GenerateMounts(PlanetMap* plMap);
    void GenerateLakes(PlanetMap* plMap);

    void TryAddNewCandSector(vector<Sector*>& fields, vector<Sector*>& candidates, Sector* sec, PlanetMap *PlMap);
    bool Contains(vector<Sector*>& fields, Sector* sec);
    bool checkNewDir(int newD, int oldD);
};

#endif // MAPGENERATOR_H
