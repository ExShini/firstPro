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
    m_objects = new genMapField**[m_width];

    //create rows
    for (int i = 0; i < width; i ++)
    {
        m_objects[i] = new genMapField*[height];
    }

    //clear mamory
    for (int i = 0; i < width; i ++)
    {
        for (int j = 0; j < width; j ++)
        {
            m_objects[i][j] = NULL;
        }
    }
}

/*************************************
FUNC: addObject(genMapField* obj, int x, int y)
DESC: add new object at room map
*************************************/
void room::addObject(genMapField* obj, int x, int y)
{
    if (x < m_width && y < m_height && y >= 0 && x >= 0)
    {
        m_objects[x][y] = obj;
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
FUNC: SetObj(ObjectsType type)
DESC: set object type and cost for current genMapField
*************************************/
void genMapField::SetObj(ObjectsType type)
{
    m_fieldType = type;

    switch(type)
    {
    case t_Floor:
        m_cost = CostFloor;
        break;
    case t_Wall:
        m_cost = CostWall;
        break;
    default:
        break;
    }
}
