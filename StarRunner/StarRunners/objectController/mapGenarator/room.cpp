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
void room::addObject(genMapField* obj, int x, int y)
{
    if (x < m_width && y < m_height && y >= 0 && x >= 0)
    {
        m_objects[genMapField::getFieldKey(x,y)] = obj;
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
