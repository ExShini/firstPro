#include "room.h"
#include "iostream"
#include "objectController/testobjects.h"

using namespace std;

room::room(int width, int height)
{
    m_width = width;
    m_height = height;
}

void room::addObject(GObject* obj, unsigned int x, unsigned int y)
{
    if (x < m_width && y < m_height)
    {
        obj->setX(x);
        obj->setY(y);
        m_objects.push_back(obj);
    }
    else
    {
        cout << "bad cordinates for object in room!" << endl;
    }
}
