#ifndef MOVABLEOBJ_H
#define MOVABLEOBJ_H

#ifdef WIN32
#include "../objectController/gobject.h"
#else
#include "objectController/gobject.h"
#endif



/************************************************************/
// All movable object should be inherited from MovableObj class
/************************************************************/
class MovableObj: public GObject
{
public:
    void move(int xDiff, int yDiff);
protected:
    MovableObj();
};

/************************************************************/
// All immovabl object should be inherited from ImmovableObj class
/************************************************************/
class ImmovableObj: public GObject
{
public:
    void move(int xDiff, int yDiff);
protected:
    ImmovableObj();
};
#endif // MOVABLEOBJ_H
