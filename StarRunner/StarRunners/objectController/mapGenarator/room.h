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
    int getWidth() { return m_width; }
    int getHeight() { return m_height; }
    genMapField*** getObjects();

protected:
    //objects map
    genMapField*** m_objects;
    //sizes should be a power of 2
    int m_width;
    int m_height;
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
      m_cost(999),
      m_fieldType(NULLOBJECT)
    {}
    Direction ParDir() { return m_parentDirection; }
    void SetObj(ObjectsType type);
    ObjectsType getObjType() { return m_fieldType; }

protected:
    Direction m_parentDirection;
    short m_cost;
    ObjectsType m_fieldType;
};

#endif // ROOM_H
