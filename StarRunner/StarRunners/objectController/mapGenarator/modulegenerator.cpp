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
void moduleGenerator::generateModule(ModuleType moduleType)
{
    list<GObject*>* moduleList = new list<GObject*>();
    list<genMapField*> ping, pong;
    list<genMapField*>* procList;

    genMapField* costMap[GENERATED_MAP_WIDTH][GENERATED_MAP_HEIGHT];

    for (int i = 0; i < GENERATED_MAP_WIDTH; i++)
    {
        for (int j = 0; j < GENERATED_MAP_HEIGHT; j++)
        {
            costMap[i][j] = new genMapField();
        }
    }

    //get rooms and plase it in map
    list<room*>* rooms = getRooms(moduleType);
    list<room*>::iterator iter = rooms->begin();

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
        //place room to cost map and obj list
        placeRoom(croom, x, y, costMap, moduleList);

    }


    //clean memory after using
    for (int i = 0; i < GENERATED_MAP_WIDTH; i++)
    {
        for (int j = 0; j < GENERATED_MAP_HEIGHT; j++)
        {
            delete costMap[i][j];
        }
    }
}


/*************************************
FUNC: placeRoom(room* croom, int x, int y, genMapField* map[][])
DESC: places room into module map
*************************************/
void moduleGenerator::placeRoom(room* croom, int x, int y,
                                genMapField* map[GENERATED_MAP_WIDTH][GENERATED_MAP_HEIGHT],
                                list<GObject*>* objList)
{
    int roomX = croom->getWidth();
    int roomY = croom->getHeight();

    for (int i = 1; i < roomX -1 ; i++)
    {
        for (int j = 1; j < roomY - 1; j++)
        {
            map[i + x][j + y]->SetCost(CostFloor);
            floor * fl = new floor();
            fl->setX(i + x);
            fl->setY(j + y);
            objList->push_back(fl);

            //get object by type here!
        }
    }

    //add wall's
    for (int i = 0; i < roomX; i++)
    {
        map[i + x][y]->SetCost(CostEmpty);
        map[i + x][y + roomY -1]->SetCost(CostEmpty);

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
        map[x][i + y]->SetCost(CostEmpty);
        map[x + roomX -1][y + i]->SetCost(CostEmpty);

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
list<room*>* moduleGenerator::getRooms(ModuleType moduleType)
{
    list<room*>* roomList = new list<room*>();
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
