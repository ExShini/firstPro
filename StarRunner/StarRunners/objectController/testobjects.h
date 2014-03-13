#ifndef TESTOBJECTS_H
#define TESTOBJECTS_H
#include "gobject.h"

class TestObject11: public GObject
{
public:
    TestObject11();
    SDL_Texture* getTexture();

    //geometry func
    virtual int getX() {return m_x;}
    virtual int getY() {return m_y;}
    virtual int getH() {return m_height;}
    virtual int getW() {return m_width;}
};

class TestObject22: public GObject
{
public:
    TestObject22();
    SDL_Texture* getTexture();

    //geometry func
    virtual int getX() {return m_x;}
    virtual int getY() {return m_y;}
    virtual int getH() {return m_height;}
    virtual int getW() {return m_width;}
};


class BackGround: public GObject
{
public:
    BackGround();
    SDL_Texture* getTexture();

    //geometry func
    virtual int getX() {return m_x;}
    virtual int getY() {return m_y;}
    virtual int getH() {return m_height;}
    virtual int getW() {return m_width;}
};

#endif // TESTOBJECTS_H
