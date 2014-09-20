#include "mapgenerator.h"

#include "objectController/objectList.h"
#include "objectController/objectcontroller.h"


/*************************************
FUNC: MapGenerator()
DESC: constructor
*************************************/
MapGenerator::MapGenerator()
{
    m_randGen = new RandomGen();
}

/*************************************
FUNC: MapGenerator()
DESC: destructor
*************************************/
MapGenerator::~MapGenerator()
{
    delete m_randGen;
}

/*************************************
FUNC: generateMap()
DESC: generate planet map
*************************************/
PlanetMap* MapGenerator::generateMap(PlanetType planetType)
{
    PlanetMap* plMap = new PlanetMap();
    int debugCounter = 0;


    for (int i = 0; i < GENERATED_MAP_WIDTH; i++)
    {
        for (int j = 0; j < GENERATED_MAP_HEIGHT; j++)
        {
            debugCounter++;
            GObject* obj = new Sector();
            obj->setX(i);
            obj->setY(j);
            (*(plMap->objects[MLEVEL_0]))[ObjectController::getFieldKey(i, j)] = obj;
        }
    }




    //init all sectors
    map<int, GObject*>::iterator iter = plMap->objects[MLEVEL_0]->begin();
    map<int, GObject*>::iterator end = plMap->objects[MLEVEL_0]->end();

    for (; iter != end; iter++)
    {
        Sector* obj = (Sector*)iter->second;
        obj->init();
    }

    return plMap;
}
