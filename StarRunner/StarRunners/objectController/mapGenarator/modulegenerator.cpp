#include "map"

#include "rooms/testroom.h"
#include "modulegenerator.h"
#include "objectController/objectList.h"

/*************************************
FUNC: moduleGenerator()
DESC: constructor
*************************************/
moduleGenerator::moduleGenerator()
{
    m_randGen = new RandomGen();
}

/*************************************
FUNC: moduleGenerator()
DESC: constructor
*************************************/
moduleGenerator::~moduleGenerator()
{
    delete m_randGen;
}

/*************************************
FUNC: generateModule(ModuleType moduleType)
DESC: generate and return module by type
*************************************/
list<GObject*>* moduleGenerator::generateModule(ModuleType moduleType)
{
    list<GObject*>* moduleList = new list<GObject*>();

    genMapField* costMap[GENERATED_MAP_WIDTH][GENERATED_MAP_HEIGHT];

    for (int i = 0; i < GENERATED_MAP_WIDTH; i++)
    {
        for (int j = 0; j < GENERATED_MAP_HEIGHT; j++)
        {
            costMap[i][j] = new genMapField();
        }
    }

    //get rooms and plase it in map
    vector<room*>* rooms = getRooms(moduleType);
    vector<room*>::iterator iter = rooms->begin();

    bool possibility = false;
    for (; iter != rooms->end(); iter++)
    {
        room* croom = *iter;
        //try get valide coordinate for room
        int x, y;
        while (possibility != true)
        {
            x = m_randGen->getRand() % (GENERATED_MAP_WIDTH - croom->getWidth());
            y = m_randGen->getRand() % (GENERATED_MAP_HEIGHT - croom->getHeight());
            possibility = checkArea(x,
                                    y,
                                    croom->getWidth(),
                                    croom->getHeight(),
                                    costMap);
        }
        //place room to cost map and floor to obj list
        placeRoom(croom, x, y, costMap, moduleList);

    }


    //try buil corridors between rooms
    int size = rooms->size();
    for (int current = 0; current < size; current++)
    {
        for (int target = current + 1; target < size; target++)
        {
            room* curRomm = (*rooms).at(current);
            room* tarRomm = (*rooms).at(target);
            createCorridors(curRomm, tarRomm, costMap);
        }
    }


    //create objects to moduleList by costMap
    for (int i = 0; i < GENERATED_MAP_WIDTH; i++)
    {
        for (int j = 0; j < GENERATED_MAP_HEIGHT; j++)
        {
            //get object by type here!
        }
    }


    //clean memory after using
    for (int i = 0; i < GENERATED_MAP_WIDTH; i++)
    {
        for (int j = 0; j < GENERATED_MAP_HEIGHT; j++)
        {
            delete costMap[i][j];
        }
    }


    return moduleList;
}


/*************************************
FUNC: createCorridors(room *croom, room *troom, genMapField *map[][])
DESC: places room into module map
*************************************/
void moduleGenerator::createCorridors(room *croom, room *troom, genMapField *genMap[GENERATED_MAP_WIDTH][GENERATED_MAP_HEIGHT])
{
    //create temrery copy
    //достаточно лишь карту стоимости скопировать?
    genMapField workCoryGM[GENERATED_MAP_WIDTH][GENERATED_MAP_HEIGHT];


    //alocate memory for maps and map's pointer
    map<int,genMapField*> ping, pong;
    map<int,genMapField*>* procList,* nextList;
    int coridorWidth = 2;

    //set default addreses for pointeres
    procList = &ping;
    nextList = &pong;

    bool processing = true;

    genMapField* startField;
    genMapField* targetField;

    //get start field
    // dividing need for normalizing coordinates
    int startX, startY;
    startX = (croom->gX() + croom->getWidth() / 2) / coridorWidth;
    startY = (croom->gY() + croom->getHeight() / 2) / coridorWidth;
    startField = genMap[startX][startY];

    (*procList)[getFieldKey(startX, startY)] = startField;

    //get target field
    int targetX, targetY;
    targetX = (troom->gX() + troom->getWidth() / 2) / coridorWidth;
    targetY = (troom->gY() + troom->getHeight() / 2) / coridorWidth;
    targetField = genMap[targetX][targetY];



    //processing until we found optimal way
    while(processing)
    {
        //process one by one
        map<int,genMapField*>::iterator iter = procList->begin();
        for (; iter != procList->end(); iter++)
        {
            //calculate coordinates for current field by key
            int key = iter->first;
            int x = key % GENERATED_MAP_WIDTH;
            int y = key / GENERATED_MAP_WIDTH;

            genMapField* cfield = iter->second;


            //*************************
            //process left side
            //check - can we build new blocks at this area?
            if (x - coridorWidth > 0)
            {
                int fieldX = x - coridorWidth;
                int fieldY = y;
                genMapField* field = genMap[fieldX][fieldY];

                //calculate cost of building this area
                int cost = 0;
                for (int i = 0; i < coridorWidth; i++)
                {
                    for (int j = 0; j < coridorWidth; j++)
                    {
                        genMapField* nearField = genMap[fieldX + i][fieldY + y];
                        cost += getCostByType(nearField->getObjType());
                    }
                }

                cost += cfield->Cost();

                if (field->Cost() > cost)
                {
                    nextList[getFieldKey(fieldX, fieldY)] = field;
                    field->setParDir(RIGHT);
                }
            }


            //*************************
            //process right side
            //check - can we build new blocks at this area?
            if ( (x + coridorWidth * 2 - 1) <  GENERATED_MAP_WIDTH)
            {
                int fieldX = x + coridorWidth;
                int fieldY = y;
                genMapField* field = genMap[fieldX][fieldY];

                //calculate cost of building this area
                int cost = 0;
                for (int i = 0; i < coridorWidth; i++)
                {
                    for (int j = 0; j < coridorWidth; j++)
                    {
                        genMapField* nearField = genMap[fieldX + i][fieldY + y];
                        cost += getCostByType(nearField->getObjType());
                    }
                }

                cost += cfield->Cost();

                if (field->Cost() > cost)
                {
                    nextList[getFieldKey(fieldX, fieldY)] = field;
                    field->setParDir(LEFT);
                }
            }


            //*************************
            //process top side
            //check - can we build new blocks at this area?
            if ( y + coridorWidth > 0)
            {
                int fieldX = x;
                int fieldY = y + coridorWidth;
                genMapField* field = genMap[fieldX][fieldY];

                //calculate cost of building this area
                int cost = 0;
                for (int i = 0; i < coridorWidth; i++)
                {
                    for (int j = 0; j < coridorWidth; j++)
                    {
                        genMapField* nearField = genMap[fieldX + i][fieldY + y];
                        cost += getCostByType(nearField->getObjType());
                    }
                }

                cost += cfield->Cost();

                if (field->Cost() > cost)
                {
                    nextList[getFieldKey(fieldX, fieldY)] = field;
                    field->setParDir(DOWN);
                }
            }


            //*************************
            //process down side
            //check - can we build new blocks at this area?
            if ( (y + coridorWidth * 2 - 1)  > 0)
            {
                int fieldX = x;
                int fieldY = y + coridorWidth;
                genMapField* field = genMap[fieldX][fieldY];

                //calculate cost of building this area
                int cost = 0;
                for (int i = 0; i < coridorWidth; i++)
                {
                    for (int j = 0; j < coridorWidth; j++)
                    {
                        genMapField* nearField = genMap[fieldX + i][fieldY + y];
                        cost += getCostByType(nearField->getObjType());
                    }
                }

                cost += cfield->Cost();

                if (field->Cost() > cost)
                {
                    nextList[getFieldKey(fieldX, fieldY)] = field;
                    field->setParDir(UP);
                }
            }

        }


        //if we haven't field for processing - finish it
        if(nextList->size() == 0)
        {
            processing = false;
        }
        else
        {
            //switch maps

        }
    }


}

/*************************************
FUNC: getCostByType(ObjectsType type)
DESC: calculate and return cost by field type
*************************************/
int moduleGenerator::getCostByType(ObjectsType type)
{
    int res = 9999;

    switch (type) {
    case t_Floor:
        res = CostFloor;
        break;
    case t_Wall:
        res = CostWall;
        break;
    case NULLOBJECT:
        res = CostEmpty;
        break;
    default:
        break;
    }

    return res;
}

/*************************************
FUNC: getFieldKey(genMapField *field)
DESC: calculate and return key for genMapField by coordinate
*************************************/
int moduleGenerator::getFieldKey(int x, int y)
{
    return y * GENERATED_MAP_WIDTH + x;
}

/*************************************
FUNC: placeRoom(room* croom, int x, int y, genMapField* map[][])
DESC: places room into module map
*************************************/
void moduleGenerator::placeRoom(room* croom, int x, int y,
                                genMapField* genMap[GENERATED_MAP_WIDTH][GENERATED_MAP_HEIGHT],
                                list<GObject*>* objList)
{
    croom->sX(x);
    croom->sY(y);

    int roomX = croom->getWidth();
    int roomY = croom->getHeight();

    for (int i = 1; i < roomX -1 ; i++)
    {
        for (int j = 1; j < roomY - 1; j++)
        {
            genMap[i + x][j + y]->SetCost(CostFloor);
            Floor * fl = new Floor();
            fl->setX(i + x);
            fl->setY(j + y);
            objList->push_back(fl);
        }
    }

    //add wall's
    for (int i = 0; i < roomX; i++)
    {
        genMap[i + x][y]->SetCost(CostEmpty);
        genMap[i + x][y + roomY -1]->SetCost(CostEmpty);

        wall * wl1 = new wall();
        wl1->setX(i + x);
        wl1->setY(y);
        objList->push_back(wl1);

        wall * wl2 = new wall();
        wl2->setX(i + x);
        wl2->setY(y + roomY -1);
        objList->push_back(wl2);
    }

    for (int i = 1; i < roomY - 1; i++)
    {
        genMap[x][i + y]->SetCost(CostEmpty);
        genMap[x + roomX -1][y + i]->SetCost(CostEmpty);

        wall * wl1 = new wall();
        wl1->setX(x);
        wl1->setY(i + y);
        objList->push_back(wl1);

        wall * wl2 = new wall();
        wl2->setX(x + roomX -1);
        wl2->setY(y + i);
        objList->push_back(wl2);
    }

}




/*************************************
FUNC: checkArea(int x, int y, int width, int height, genMapField* map[][])
DESC: return true if place is free, else - false
*************************************/
bool moduleGenerator::checkArea(int x,
                                int y,
                                int width,
                                int height,
                                genMapField* map[GENERATED_MAP_WIDTH][GENERATED_MAP_HEIGHT])
{
    bool res = true;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (map[x + i][y + j]->getObjType() != NULLOBJECT)
                res = false;
        }
    }

    return res;
}

/*************************************
FUNC: getRooms(ModuleType moduleType)
DESC: return list of rooms for current module type
*************************************/
vector<room *> *moduleGenerator::getRooms(ModuleType moduleType)
{
    vector<room*>* roomList = new vector<room*>();
    switch(moduleType)
    {
    case ResidentialUnit:
        roomList->push_back(new testRoom());
        roomList->push_back(new testRoom());
        roomList->push_back(new testRoom());
        roomList->push_back(new testRoom());
        roomList->push_back(new testRoom());
        roomList->push_back(new testRoom());
        break;
    default:
        break;
    }

    return roomList;
}
