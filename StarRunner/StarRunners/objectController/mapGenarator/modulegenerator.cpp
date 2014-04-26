#include "iostream"

#include "map"

#include "rooms/testroom.h"
#include "modulegenerator.h"
#include "objectController/objectList.h"
#include "objectController/objectcontroller.h"

using namespace std;

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
Module *moduleGenerator::generateModule(ModuleType moduleType)
{
    Module* module = new Module();

    for (int i = 0; i < GENERATED_MAP_WIDTH; i++)
    {
        for (int j = 0; j < GENERATED_MAP_HEIGHT; j++)
        {
            m_costMap[i][j] = new genMapField();
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
            x = (m_randGen->getRand()) % (GENERATED_MAP_WIDTH - croom->getWidth() - roomBorder * 2) + roomBorder;
            y = (m_randGen->getRand()) % (GENERATED_MAP_HEIGHT - croom->getHeight() - roomBorder * 2) + roomBorder;
            possibility = checkArea(x, y, croom);
        }
        //place room to cost map and floor to obj list
        placeRoom(croom, x, y);
        possibility = false;

    }


    //try buil corridors between rooms
    int size = rooms->size();
    for (int current = 0; current < size; current++)
    {
        for (int target = current + 1; target < size; target++)
        {
            room* curRomm = (*rooms).at(current);
            room* tarRomm = (*rooms).at(target);
            createCorridors(curRomm, tarRomm);
        }
    }


    //create objects to moduleList by m_costMap
    for (int i = 0; i < GENERATED_MAP_WIDTH; i++)
    {
        for (int j = 0; j < GENERATED_MAP_HEIGHT; j++)
        {

            genMapField* field = m_costMap[i][j];

            for (int ml = MLEVEL_0; ml < NUM_LEVELS; ml++)
            {
                //get object by type here!
                GObject* obj = getGObjectByType(field->getObjType((ModuleObjLevel)ml));
                if (obj != NULL)
                {
                    obj->setX(i);
                    obj->setY(j);
                    //set objects to model
                    (*(module->objects[ml]))[ObjectController::getFieldKey(i, j)] = obj;
                }
                else if (ml == MLEVEL_0)
                {
                    //check near fields
                    bool isWall = false;

                    //right field
                    if (i < GENERATED_MAP_WIDTH - 1)
                    {
                        isWall |= (m_costMap[i + 1][j]->getObjType(MLEVEL_0) == t_Floor);
                        //right down field
                        if (j < GENERATED_MAP_HEIGHT - 1)
                            isWall |= (m_costMap[i + 1][j + 1]->getObjType(MLEVEL_0) == t_Floor);

                        //right top field
                        if (j > 0)
                            isWall |= (m_costMap[i + 1][j - 1]->getObjType(MLEVEL_0) == t_Floor);
                    }

                    //left field
                    if (i > 0)
                    {
                        isWall |= (m_costMap[i - 1][j]->getObjType(MLEVEL_0) == t_Floor);

                        //left down field
                        if (j < GENERATED_MAP_HEIGHT - 1)
                            isWall |= (m_costMap[i - 1][j + 1]->getObjType(MLEVEL_0) == t_Floor);

                        //left top field
                        if (j > 0)
                            isWall |= (m_costMap[i - 1][j - 1]->getObjType(MLEVEL_0) == t_Floor);
                    }
                    if (j < GENERATED_MAP_HEIGHT - 1)
                        isWall |= (m_costMap[i][j + 1]->getObjType(MLEVEL_0) == t_Floor);
                    if (j > 0)
                        isWall |= (m_costMap[i][j - 1]->getObjType(MLEVEL_0) == t_Floor);

                    if (isWall)
                    {
                        field->setObjType(t_Wall, MLEVEL_0);
                        obj = getGObjectByType(t_Wall);
                        obj->setX(i);
                        obj->setY(j);
                        (*(module->objects[ml]))[ObjectController::getFieldKey(i, j)] = obj;
                    }
                }
            }
        }
    }


    //clean memory after using
    for (int i = 0; i < GENERATED_MAP_WIDTH; i++)
    {
        for (int j = 0; j < GENERATED_MAP_HEIGHT; j++)
        {
            if (m_costMap[i][j] != NULL)
                delete m_costMap[i][j];
        }
    }


    return module;
}



GObject* moduleGenerator::getGObjectByType(ObjectsType type)
{
    GObject* obj = NULL;

    switch (type)
    {
    case t_Floor:
        obj = new Floor();
        break;
    case t_Wall:
        obj = new wall();
        break;
    case t_Door:
        obj = new Door();
        break;
    case t_MedBox:
        obj = new MedBox();
        break;
    case t_SF:
        obj = new SF();
        break;
    case NULLOBJECT:
        break;

    default:
        cout << "Try to create GObject by unknown type" << endl;
        break;
    }

    return obj;
}



/*************************************
FUNC: createCorridors(room *croom, room *troom, genMapField *map[][])
DESC: places room into module map
*************************************/
void moduleGenerator::createCorridors(room *croom, room *troom)
{

    //refresh map costs and set default value
    for (int i = 0; i < GENERATED_MAP_WIDTH; i++)
    {
        for (int j = 0; j < GENERATED_MAP_HEIGHT; j++)
        {
            m_costMap[i][j]->SetCost(9999);
        }
    }


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
    // also we should normalize coordinates
    int startX, startY;
    startX = croom->gX() + croom->getWidth() / 2;
    startY = croom->gY() + croom->getHeight() / 2;

    //normolize here
    startX -= startX % coridorWidth;
    startY -= startY % coridorWidth;

    startField = m_costMap[startX][startY];
    startField->SetCost(0);

    //set strart point for processing
    (*procList)[ObjectController::getFieldKey(startX, startY)] = startField;

    //get target field
    int targetX, targetY;
    targetX = troom->gX() + troom->getWidth() / 2;
    targetY = troom->gY() + troom->getHeight() / 2;

    //normolize here
    targetX -= targetX % coridorWidth;
    targetY -= targetY % coridorWidth;

    targetField = m_costMap[targetX][targetY];



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
            if (x - coridorWidth >= 0)
            {
                int fieldX = x - coridorWidth;
                int fieldY = y;
                genMapField* field = m_costMap[fieldX][fieldY];

                //calculate cost of building this area

                int cost = 0;
                cost = getFieldCost(fieldX, fieldY, coridorWidth);
                cost += cfield->Cost();

                if (field->Cost() > cost)
                {
                    (*nextList)[ObjectController::getFieldKey(fieldX, fieldY)] = field;
                    field->SetCost(cost);
                    field->setParDir(RIGHT);
                    field->setParent(cfield);
                }
            }


            //*************************
            //process right side
            //check - can we build new blocks at this area?
            if ( (x + coridorWidth * 2 - 1) <  GENERATED_MAP_WIDTH)
            {
                int fieldX = x + coridorWidth;
                int fieldY = y;
                genMapField* field = m_costMap[fieldX][fieldY];

                //calculate cost of building this area
                int cost = 0;
                cost = getFieldCost(fieldX, fieldY, coridorWidth);
                cost += cfield->Cost();

                if (field->Cost() > cost)
                {
                    (*nextList)[ObjectController::getFieldKey(fieldX, fieldY)] = field;
                    field->SetCost(cost);
                    field->setParDir(LEFT);
                    field->setParent(cfield);
                }
            }


            //*************************
            //process top side
            //check - can we build new blocks at this area?
            if ( y - coridorWidth >= 0)
            {
                int fieldX = x;
                int fieldY = y - coridorWidth;
                genMapField* field = m_costMap[fieldX][fieldY];

                //calculate cost of building this area
                int cost = 0;
                cost = getFieldCost(fieldX, fieldY, coridorWidth);
                cost += cfield->Cost();

                if (field->Cost() > cost)
                {
                    (*nextList)[ObjectController::getFieldKey(fieldX, fieldY)] = field;
                    field->SetCost(cost);
                    field->setParDir(DOWN);
                    field->setParent(cfield);
                }
            }


            //*************************
            //process down side
            //check - can we build new blocks at this area?
            if ( (y + coridorWidth * 2 - 1) < GENERATED_MAP_HEIGHT)
            {
                int fieldX = x;
                int fieldY = y + coridorWidth;
                genMapField* field = m_costMap[fieldX][fieldY];

                //calculate cost of building this area
                int cost = 0;
                cost = getFieldCost(fieldX, fieldY, coridorWidth);
                cost += cfield->Cost();

                if (field->Cost() > cost)
                {
                    (*nextList)[ObjectController::getFieldKey(fieldX, fieldY)] = field;
                    field->SetCost(cost);
                    field->setParDir(UP);
                    field->setParent(cfield);
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
            map<int,genMapField*>* tempPointer;

            tempPointer = procList;
            procList = nextList;
            nextList = tempPointer;
            //clear nextList map for next loop
            nextList->clear();
        }
    }


    //build corridors

    genMapField* processField = targetField;
    int procX = targetX;
    int procY = targetY;

    //process until we returned to start point

    while (processField != startField)
    {

        processField = m_costMap[procX][procY];

        //build current block around processField
        for (int i = procX; i < procX + coridorWidth; i ++)
        {
            for (int j = procY; j < procY + coridorWidth; j++)
            {
                //set floor to 0 level
                m_costMap[i][j]->setObjType(t_Floor, MLEVEL_0);

                //clear 1 level
                m_costMap[i][j]->setObjType(NULLOBJECT, MLEVEL_1);

                //set NULLOBJECT or Door type to top (2 level)
                if (m_costMap[i][j]->getObjType(MLEVEL_2) == t_Door ||
                        m_costMap[i][j]->getObjType(MLEVEL_2) == t_Wall)
                {
                    m_costMap[i][j]->setObjType(t_Door, MLEVEL_2);
                }
                else
                {
                    m_costMap[i][j]->setObjType(NULLOBJECT, MLEVEL_2);
                }
            }
        }

        //switch to next field
        switch (processField->ParDir()) {
        case UP:
            procY -= coridorWidth;
            break;
        case DOWN:
            procY += coridorWidth;
            break;
        case LEFT:
            procX -= coridorWidth;
            break;
        case RIGHT:
            procX += coridorWidth;
            break;
        default:
            cout << "We have a problem in coridor geniration!" << endl;
            break;
        }
    }

}


/*************************************
FUNC: getFieldCost(int x, int y, int coridorWidth)
DESC: calculate and return cost for current field
*************************************/
int moduleGenerator::getFieldCost(int x, int y, int coridorWidth)
{
    int cost = 0;
    for (int i = 0; i < coridorWidth; i++)
    {
        for (int j = 0; j < coridorWidth; j++)
        {
            genMapField* nearField = m_costMap[x + i][y + j];
            for (int level = MLEVEL_0; level < NUM_LEVELS; level++)
            {
                cost += getCostByType(nearField->getObjType((ModuleObjLevel)level));
            }
        }
    }

    return cost;
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
    case t_Door:
        res = CostFloor;
        break;
    case t_Wall:
        res = CostWall;
        break;
    case t_MedBox:
    case t_SF:
        res = CostItem;
        break;
    case NULLOBJECT:
        res = CostEmpty;
        break;
    default:
        cout << "Try get cost by unknoun type" << endl;
        break;
    }

    return res;
}



/*************************************
FUNC: placeRoom(room* croom, int x, int y, genMapField* map[][])
DESC: places room into module map
*************************************/
void moduleGenerator::placeRoom(room* croom, int x, int y)
{
    croom->sX(x);
    croom->sY(y);

    map<int, genMapField*>::iterator iter = croom->getObjects()->begin();
    map<int, genMapField*>::iterator end = croom->getObjects()->end();

    for ( ; iter != end; iter++)
    {
        int key = iter->first;
        int cx = key % GENERATED_MAP_WIDTH;
        int cy = key / GENERATED_MAP_WIDTH;

        //set each object to position
        for (int ml = MLEVEL_0; ml < NUM_LEVELS; ml++)
        {
            m_costMap[x + cx][y + cy]->setObjType
                    (
                        ((genMapField*)(iter->second))->getObjType((ModuleObjLevel)ml),
                        (ModuleObjLevel)ml
                    );
        }

    }

}


/*************************************
FUNC: checkArea(int x, int y, int width, int height, genMapField* map[][])
DESC: return true if place for room is free, in over case - false
*************************************/
bool moduleGenerator::checkArea(int x, int y,room * croom)
{
    bool res = true;

    map<int, genMapField*>::iterator iter = croom->getObjects()->begin();

    //обавить проверку зоны очуждения!
    for (;iter != croom->getObjects()->end(); iter++)
    {
        int key = iter->first;
        int cx = key % GENERATED_MAP_WIDTH;
        int cy = key / GENERATED_MAP_WIDTH;

        //check all module levels
        for (int ml = MLEVEL_0; ml < NUM_LEVELS; ml++)
        {
            ObjectsType type = m_costMap[x + cx][y + cy]->getObjType((ModuleObjLevel)ml);
            if (type != NULLOBJECT /*&& type != t_Wall*/)
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
        roomList->push_back(new testRoom());
        roomList->push_back(new testRoom());
        roomList->push_back(new testRoom());
        roomList->push_back(new testRoom());
        roomList->push_back(new testRoom());
        roomList->push_back(new testRoom());


        roomList->push_back(new testRoom2());
        roomList->push_back(new testRoom2());
        roomList->push_back(new testRoom2());
        roomList->push_back(new testRoom2());
        roomList->push_back(new testRoom2());
        roomList->push_back(new testRoom2());
        roomList->push_back(new testRoom2());
        roomList->push_back(new testRoom2());
        roomList->push_back(new testRoom2());
        break;
    default:
        break;
    }

    return roomList;
}
