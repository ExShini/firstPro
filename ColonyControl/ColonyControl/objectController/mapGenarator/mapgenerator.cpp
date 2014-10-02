#include "mapgenerator.h"

#include "objectController/objectList.h"
#include "objectController/objectcontroller.h"

#include "iostream"
using namespace std;


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
    cout << "Creating" << endl;
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


    GenerateFertility(plMap);
    GenerateMinerals(plMap);

    cout << "Initing secs" << endl;
    //init all sectors
    for (int i = 0; i < GENERATED_MAP_WIDTH; i++)
    {
        for (int j = 0; j < GENERATED_MAP_HEIGHT; j++)
        {
            Sector* obj = (Sector*) plMap->objects[SECTOR_LEVEL]->lMap[i][j];
            obj->init();
        }
    }

    cout << "Generate mounts" << endl;
    GenerateMounts(plMap);
    cout << "Generate lakes" << endl;
    GenerateLakes(plMap);
    cout << "end of generate" << endl;



    return plMap;
}


void MapGenerator::GenerateFertility(PlanetMap *plMap)
{
    for (int i = 0; i < LAVA_PLANET_NUMBER_OF_FERTILITY_FIELDS; i++)
    {
        int x = m_randGen->getRand() % MAP_WIDTH;
        int y = m_randGen->getRand() % MAP_HEIGHT;

        vector<Sector*> fields;
        vector<Sector*> candidates;
        vector<int> fieldsTime;
        Sector* sec = (Sector*)plMap->objects[SECTOR_LEVEL]->lMap[x][y];
        fields.push_back(sec);
        fieldsTime.push_back(0);

        for (int j = 0; j < LAVA_PLANET_TIME_OF_FERTILITY_FIELDS; j++)
        {

            //add field time for each sectors
            for (unsigned int k = 0; k < fields.size(); k++)
            {
                fieldsTime[k]++;
            }

            //add new candidate to field array
            for (unsigned int k = 0; k < candidates.size(); k++)
            {
                Sector* cand = candidates[k];
                fields.push_back(cand);
                fieldsTime.push_back(0);
            }

            //try to find new candidate to candidate array
            candidates.clear();
            for(unsigned int k = 0; k < fields.size(); k++)
            {
                Sector* field = fields[k];
                TryAddNewCandSector(fields, candidates, field, plMap);
            }
        }

        //set new fertility fow each fields in fields arrey
        for(unsigned int k = 0; k < fields.size(); k++)
        {
            Sector* field = fields[k];
            int time = fieldsTime[k];
            int fertility = field->getFertility() + time * LAVA_PLANET_POWER_OF_FERTILITY_FIELDS;
            field->setFertility(fertility);
        }
    }
}



void MapGenerator::GenerateMinerals(PlanetMap *plMap)
{
    for (int i = 0; i < LAVA_PLANET_NUMBER_OF_MINERAL_FIELDS; i++)
    {
        vector<Sector*> fields;
        vector<Sector*> candidates;
        vector<int> fieldsTime;

        int x = m_randGen->getRand() % MAP_WIDTH;
        int y = m_randGen->getRand() % MAP_HEIGHT;

        int mineralFieldLength = m_randGen->getRand() % LAVA_PLANET_LEGHT_OF_MINERAL_FIELDS + 1;
        int oldDir = NO_DIR;
        int newDir = NO_DIR;

        //choose first meneral fields
        for (int j = 0; j < mineralFieldLength; j++)
        {
            Sector* sec = (Sector*)plMap->objects[SECTOR_LEVEL]->lMap[x][y];
            fields.push_back(sec);
            fieldsTime.push_back(0);

            //choose new direction
            bool findNewDir = false;
            while(!findNewDir)
            {
                newDir = m_randGen->getRand() % NUMBER_OF_DIRECTIONS;
                if (checkNewDir(newDir, oldDir))
                    findNewDir = true;
            }

            //correct coordinates
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

        //process all mineral area
        for (int j = 0; j < LAVA_PLANET_TIME_OF_MINERAL_FIELDS; j++)
        {

            //add new candidate to field array
            for (unsigned int k = 0; k < candidates.size(); k++)
            {
                Sector* cand = candidates[k];
                fields.push_back(cand);
                fieldsTime.push_back(0);
            }

            //add field time for each sectors
            for (unsigned int k = 0; k < fields.size(); k++)
            {
                fieldsTime[k]++;
            }

            //try to find new candidate to candidate array
            candidates.clear();
            for(unsigned int k = 0; k < fields.size(); k++)
            {
                Sector* field = fields[k];
                TryAddNewCandSector(fields, candidates, field, plMap);
            }
        }

        //set new minerals fow each fields in fields arrey
        for(unsigned int k = 0; k < fields.size(); k++)
        {
            Sector* field = fields[k];
            int time = fieldsTime[k];
            int mineral = field->getMineralWealth() + time * LAVA_PLANET_POWER_OF_MINERAL_FIELDS;
            field->setMineralWealth(mineral);
        }
    }

}

bool MapGenerator::checkNewDir(int newD, int oldD)
{
    bool res = true;

    if(newD == UP && oldD == DOWN)
        res = false;

    if(newD == DOWN && oldD == UP)
        res = false;

    if(newD == LEFT && oldD == RIGHT)
        res = false;

    if(newD == RIGHT && oldD == LEFT)
        res = false;

    return res;
}


void MapGenerator::TryAddNewCandSector(vector<Sector *> &fields, vector<Sector *> &candidates, Sector* sec, PlanetMap* PlMap)
{
    int fx = sec->getX();
    int fy = sec->getY();

    //LEFT side
    int newX = fx - 1;
    int newY = fy;

    if (newX >= 0)
    {
        Sector* candSec = (Sector*)PlMap->objects[SECTOR_LEVEL]->lMap[newX][newY];

        if (!Contains(fields, candSec) && !Contains(candidates, candSec))
        {
            candidates.push_back(candSec);
        }
    }

    //RIGHT side
    newX = fx + 1;
    newY = fy;

    if (newX < MAP_WIDTH)
    {
        Sector* candSec = (Sector*)PlMap->objects[SECTOR_LEVEL]->lMap[newX][newY];

        if (!Contains(fields, candSec) && !Contains(candidates, candSec))
        {
            candidates.push_back(candSec);
        }
    }

    //TOP side
    newX = fx;
    newY = fy - 1;

    if (newY >= 0)
    {
        Sector* candSec = (Sector*)PlMap->objects[SECTOR_LEVEL]->lMap[newX][newY];

        if (!Contains(fields, candSec) && !Contains(candidates, candSec))
        {
            candidates.push_back(candSec);
        }
    }

    //DOWN side
    newX = fx;
    newY = fy + 1;

    if (newY < MAP_HEIGHT)
    {
        Sector* candSec = (Sector*)PlMap->objects[SECTOR_LEVEL]->lMap[newX][newY];

        if (!Contains(fields, candSec) && !Contains(candidates, candSec))
        {
            candidates.push_back(candSec);
        }
    }
}


bool MapGenerator::Contains(vector<Sector *> &fields, Sector* sec)
{
    for (unsigned int i = 0; i < fields.size(); i++)
    {
        Sector* checkSec = fields[i];
        if (sec == checkSec)
            return true;
    }

    return false;
}


void MapGenerator::GenerateMounts(PlanetMap *plMap)
{
    for (int i = 0; i < LAVA_PLANET_NUMBER_OF_MOUNT; i++)
    {
        int oldDir = NO_DIR;
        int newDir = NO_DIR;

        int x = m_randGen->getRand() % MAP_WIDTH;
        int y = m_randGen->getRand() % MAP_HEIGHT;

        int mountlength = m_randGen->getRand() % LAVA_PLANET_MOUNT_LINGHT + 1;

        for (int j = 0; j < mountlength; j++)
        {
            Sector* sec = (Sector*)plMap->objects[SECTOR_LEVEL]->lMap[x][y];
            if(sec->getType() == t_Sector)
                j--;

            GObject* mount = new LavaMount();
            mount->setX(x);
            mount->setY(y);
            plMap->objects[SECTOR_LEVEL]->lMap[x][y] = mount;

            //choose new direction
            bool findNewDir = false;
            while(!findNewDir)
            {
                newDir = m_randGen->getRand() % NUMBER_OF_DIRECTIONS;
                if (checkNewDir(newDir, oldDir))
                    findNewDir = true;
            }

            newDir = m_randGen->getRand() % NUMBER_OF_DIRECTIONS;

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
        }
    }
}

void MapGenerator::GenerateLakes(PlanetMap *plMap)
{
    for (int i = 0; i < LAVA_PLANET_NUMBER_OF_LAVA_LAKES; i++)
    {
        int oldDir = NO_DIR;
        int newDir = NO_DIR;

        int x = m_randGen->getRand() % MAP_WIDTH;
        int y = m_randGen->getRand() % MAP_HEIGHT;

        int mountlength = m_randGen->getRand() % LAVA_PLANET_LAVA_LAKES_LINGHT + 1;

        for (int j = 0; j < mountlength; j++)
        {
            Sector* sec = (Sector*)plMap->objects[SECTOR_LEVEL]->lMap[x][y];
            if (sec->getType() != t_Sector)
            {
                j--;
            }

            delete sec;

            GObject* lava = new Lava();
            lava->setX(x);
            lava->setY(y);
            plMap->objects[SECTOR_LEVEL]->lMap[x][y] = lava;


            //choose new direction
            bool findNewDir = false;
            while(!findNewDir)
            {
                newDir = m_randGen->getRand() % NUMBER_OF_DIRECTIONS;
                if (checkNewDir(newDir, oldDir))
                    findNewDir = true;
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
        }
    }
}
