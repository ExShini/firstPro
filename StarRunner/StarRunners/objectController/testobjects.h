#ifndef TESTOBJECTS_H
#define TESTOBJECTS_H
#include "movableobj.h"

class TestObject11: public MovableObj
{
public:
    TestObject11();
    SDL_Texture* getTexture();

};

class TestObject22: public ImmovableObj
{
public:
    TestObject22();
    SDL_Texture* getTexture();

};


class BackGround: public GObject
{
public:
    BackGround();
    SDL_Texture* getTexture();

};

#endif // TESTOBJECTS_H
