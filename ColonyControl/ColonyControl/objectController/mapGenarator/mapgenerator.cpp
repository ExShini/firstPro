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

	// Поправить!!!
    for (int i = 0; i < GENERATED_MAP_WIDTH; i++)
    {
        for (int j = 0; j < GENERATED_MAP_HEIGHT; j++)
        {
            debugCounter++;
            GObject* obj = new Sector();
            obj->setX(i);
            obj->setY(j);
            plMap->objects[SECTOR_LEVEL]->lMap[i][j] = obj;
        }
    }




    //init all sectors
	// Поправить!!!
	for (int i = 0; i < GENERATED_MAP_WIDTH; i++)
    {
        for (int j = 0; j < GENERATED_MAP_HEIGHT; j++)
        {
            Sector* obj = (Sector*) plMap->objects[SECTOR_LEVEL]->lMap[i][j];
            obj->init();
        }
    }
	

    return plMap;
}
