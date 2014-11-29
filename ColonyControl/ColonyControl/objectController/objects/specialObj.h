#ifndef TESTOBJECTS_H
#define TESTOBJECTS_H
#include "../movableobj.h"

class CameraObject: public MovableObj
{
public:
    CameraObject();

};

class TargetObject: public MovableObj
{
public:
    TargetObject();
    bool isValidLink();
};

class BackGround: public ImmovableObj
{
public:
    BackGround();

};

#endif // TESTOBJECTS_H
