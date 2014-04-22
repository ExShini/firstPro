#ifndef ROOM_H
#define ROOM_H
#include "map"

#include "enums/moduleGeneratorSattings.h"
#include "enums/objects.h"

//find definition for genMapField at the end of this file
class genMapField;

using namespace std;

/****************************************************************************
room class!
****************************************************************************/

class room
{
public:
    room(int width, int height);

    void addObject(ObjectsType *obj, int x, int y);
    map<int, genMapField*>* getObjects() { return m_objects; }

    int getWidth() { return m_width; }
    int getHeight() { return m_height; }

    int gX() { return m_x; }
    int gY() { return m_y; }

    void sX(int x) { m_x = x; }
    void sY(int y) { m_y = y; }

protected:
    //objects map
     map<int, genMapField*>* m_objects;
    //sizes should be a power of 2
    int m_width;
    int m_height;
    int m_x;
    int m_y;
};

/****************************************************************************
genMapField class!
Support class. It contain members, which used at module generation phase
****************************************************************************/
class genMapField
{
public:
    genMapField():
      m_parentDirection(NODIR),
      m_parent(0),
      m_cost(9999)
    {
        for(int i = 0; i < NUM_LEVELS; i++)
            m_fieldType[i] = NULLOBJECT;
    }

    void setParDir(Direction dir) { m_parentDirection = dir; }
    Direction ParDir() { return m_parentDirection; }

    genMapField* Parent() { return m_parent; }
    void setParent(genMapField* parent) { m_parent = parent; }

    void setObjType(ObjectsType type, ModuleGenLevel level) { m_fieldType[level] = type; }
    ObjectsType getObjType() { return m_fieldType; }

    void SetCost(short cost) { m_cost = cost; }
    short Cost() { return m_cost; }

    /***********************/
    static int getFieldKey(int x, int y);

protected:
    Direction m_parentDirection;
    genMapField * m_parent;
    short m_cost;
    ObjectsType m_fieldType[NUM_LEVELS];
};

#endif // ROOM_H
