#ifndef TESTOBJECTS_H
#define TESTOBJECTS_H
#include "../movableobj.h"

class CameraObject: public MovableObj
{
public:
    CameraObject();

};


class BackGround: public ImmovableObj
{
public:
    BackGround();

};

#endif // TESTOBJECTS_H
