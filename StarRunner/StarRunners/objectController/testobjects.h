#ifndef TESTOBJECTS_H
#define TESTOBJECTS_H
#include "movableobj.h"

class TestObject11: public MovableObj
{
public:
    TestObject11();

};

class TestObject22: public ImmovableObj
{
public:
    TestObject22();

};


class BackGround: public ImmovableObj
{
public:
    BackGround();

};

#endif // TESTOBJECTS_H
