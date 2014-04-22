#include "room.h"
#include "iostream"

using namespace std;

/*************************************
FUNC: room()
DESC: constructor
*************************************/
room::room(int width, int height)
{
    m_width = width;
    m_height = height;

    //create columns;
    m_objects = map<int, genMapField*>();

}

/*************************************
FUNC: addObject(genMapField* obj, int x, int y)
DESC: add new object at room map
*************************************/
void room::addObject(ObjectsType* obj, int x, int y)
{
    if (x < m_width && y < m_height && y >= 0 && x >= 0)
    {
        int key = genMapField::getFieldKey(x,y);
        map<int, genMapField*>::iterator iter = m_objects->find(key);

        genMapField* addedObj;

        if (iter == m_objects->end())
        {
            addedObj = new genMapField();
            (*m_objects)[key] = addedObj;
        }
        else
        {
            addedObj = iter->second;
        }

        switch (obj) {
        case t_Floor:
            addedObj->setObjType(obj, MLEVEL_0);
            break;
        case t_Wall:
        case t_Door:
            addedObj->setObjType(obj, MLEVEL_2);
        default:
            cout << "You try add unknown object to room";
            break;
        }
    }
    else
    {
        cout << "bad cordinates for object in room!" << endl;
    }
}




/****************************************************************************
genMapField class!
Support class. It contain members, which used at module generation phase
****************************************************************************/
/*************************************
FUNC: getFieldKey(genMapField *field)
DESC: calculate and return key for genMapField by coordinate
*************************************/
int genMapField::getFieldKey(int x, int y)
{
    return y * GENERATED_MAP_WIDTH + x;
}
