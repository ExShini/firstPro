#ifndef ROOM_H
#define ROOM_H
#include "list"
#include "objectController/gobject.h"

class room
{
public:
    room(int width, int height);
    void addObject(GObject* obj, unsigned int x, unsigned int y);

protected:

    list<GObject*> m_objects;
    //sizes should be a power of 2
    int m_width;
    int m_height;
}

#endif // ROOM_H
