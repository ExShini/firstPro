#include "rooms/testroom.h"
#include "modulegenerator.h"

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



    }

}

/*************************************
FUNC: checkArea(int x, int y, int width, int height, genMapField*** map)
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
