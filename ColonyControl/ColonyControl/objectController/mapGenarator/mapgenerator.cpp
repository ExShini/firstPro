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
            plMap->objects[SECTOR_LEVEL]->lMap[i][j] = obj;
        }
    }


    //init all sectors
    for (int i = 0; i < GENERATED_MAP_WIDTH; i++)
    {
        for (int j = 0; j < GENERATED_MAP_HEIGHT; j++)
        {
            Sector* obj = (Sector*) plMap->objects[SECTOR_LEVEL]->lMap[i][j];
            obj->init();
        }
    }

    GenerateMounts(plMap);
    GenerateLakes(plMap);



    return plMap;
}

void MapGenerator::GenerateMounts(PlanetMap *plMap)
{
    for (int i = 0; i < LAVA_PLANET_NUMBER_OF_MOUNT; i++)
    {
        int x = m_randGen->getRand() % MAP_WIDTH;
        int y = m_randGen->getRand() % MAP_HEIGHT;

        int mountlength = m_randGen->getRand() % LAVA_PLANET_MOUNT_LINGHT + 1;
        int oldDir = NO_DIR;

        for (int j = 0; j < mountlength; j++)
        {
            Sector* sec = (Sector*)plMap->objects[SECTOR_LEVEL]->lMap[x][y];
            if (sec->getType() != t_Sector)
            {
                j--;
            }
            else
            {
                delete sec;

                GObject* mount = new LavaMount();
                mount->setX(x);
                mount->setY(y);
                plMap->objects[SECTOR_LEVEL]->lMap[x][y] = mount;
            }

            int newDir = m_randGen->getRand() % NUMBER_OF_DIRECTIONS;

            if (newDir == UP && y > 0)
            {
                y--;
            }
            else if (newDir == DOWN && y < MAP_HEIGHT - 1)
            {
                y++;
            }
            else if(newDir == LEFT && x > 0)
            {
                x--;
            }
            else if(newDir == RIGHT && x < MAP_WIDTH - 1)
            {
                x++;
            }


            oldDir = newDir;
        }
    }
}

void MapGenerator::GenerateLakes(PlanetMap *plMap)
{
    for (int i = 0; i < LAVA_PLANET_NUMBER_OF_LAVA_LAKES; i++)
    {
        int x = m_randGen->getRand() % MAP_WIDTH;
        int y = m_randGen->getRand() % MAP_HEIGHT;

        int mountlength = m_randGen->getRand() % LAVA_PLANET_LAVA_LAKES_LINGHT + 1;
        int oldDir = NO_DIR;

        for (int j = 0; j < mountlength; j++)
        {
            Sector* sec = (Sector*)plMap->objects[SECTOR_LEVEL]->lMap[x][y];
            if (sec->getType() != t_Sector)
            {
                j--;
            }
            else
            {
                delete sec;

                GObject* lava = new Lava();
                lava->setX(x);
                lava->setY(y);
                plMap->objects[SECTOR_LEVEL]->lMap[x][y] = lava;
            }

            int newDir = m_randGen->getRand() % NUMBER_OF_DIRECTIONS;

            if (newDir == UP && y > 0)
            {
                y--;
            }
            else if (newDir == DOWN && y < MAP_HEIGHT - 1)
            {
                y++;
            }
            else if(newDir == LEFT && x > 0)
            {
                x--;
            }
            else if(newDir == RIGHT && x < MAP_WIDTH - 1)
            {
                x++;
            }


            oldDir = newDir;
        }
    }
}
