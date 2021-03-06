#ifndef MOVABLEOBJ_H
#define MOVABLEOBJ_H
#include "objectController/gobject.h"

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
