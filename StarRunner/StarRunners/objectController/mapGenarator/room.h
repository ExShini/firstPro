#ifndef ROOM_H
#define ROOM_H
#include "enums/moduleGeneratorSattings.h"
#include "enums/objects.h"

//find definition for genMapField at the end of this file
class genMapField;

/****************************************************************************
room class!
****************************************************************************/

class room
{
public:
    room(int width, int height);

    void addObject(genMapField* obj, int x, int y);
    genMapField*** getObjects() { return m_objects; }

    int getWidth() { return m_width; }
    int getHeight() { return m_height; }

    int gX() { return m_x; }
    int gY() { return m_y; }

    void sX(int x) { m_x = x; }
    void sY(int y) { m_y = y; }

protected:
    //objects map
    genMapField*** m_objects;
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
      m_cost(9999),
      m_fieldType(NULLOBJECT)
    {}

    void setParDir(Direction dir) { m_parentDirection = dir; }
    Direction ParDir() { return m_parentDirection; }

    void setObjType(ObjectsType type) { m_fieldType = type; }
    ObjectsType getObjType() { return m_fieldType; }

    void SetCost(short cost) { m_cost = cost; }
    short Cost() { return m_cost; }

protected:
    Direction m_parentDirection;
    short m_cost;
    ObjectsType m_fieldType;
};

#endif // ROOM_H
