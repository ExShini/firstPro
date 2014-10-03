#ifndef GOBJECT_H
#define GOBJECT_H

#ifdef WIN32
#include "../render/textureprovider.h"
#else
#include "render/textureprovider.h"
#endif


class GObject
{
public:
    virtual ~GObject();
    virtual FrameController * getFController() { return m_fcontroller; }

    //geometry func
    virtual int getX() { return m_x; }
    virtual int getY() { return m_y; }
    virtual int getH() { return m_height; }
    virtual int getW() { return m_width; }
    virtual ObjectsType getType() { return m_type; }


    virtual void setX(int x) { m_x = x;}
    virtual void setY(int y) { m_y = y;}
    virtual void setH(int height) { m_height = height;}
    virtual void setW(int width) { m_width = width;}



protected:
    GObject();

    //coordinates and sizes
    int m_x;
    int m_y;
    int m_width;
    int m_height;

    FrameController * m_fcontroller;
    ObjectsType m_type;
};

#endif // GOBJECT_H
