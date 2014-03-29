#ifndef ROOM_H
#define ROOM_H
#include "enums/moduleGeneratorSattings.h"
#include "enums/objects.h"

#include "list"

/****************************************************************************
genMapField class!
Support class. It contain members, which used at module generation phase
****************************************************************************/
class genMapField
{
public:
    genMapField():
      m_parentDirection(NODIR),
      m_cost(999),
      m_fieldType(NULLOBJECT)
    {}
    Direction ParDir() { return m_parentDirection; }
protected:
    Direction m_parentDirection;
    short m_cost;
    ObjectsType m_fieldType;
};

/****************************************************************************
room class!
****************************************************************************/

class room
{
public:
    room(int width, int height);
    void addObject(genMapField* obj, int x, int y);

protected:
    //objects map
    genMapField*** m_objects;
    //sizes should be a power of 2
    int m_width;
    int m_height;
};



#endif // ROOM_H
