#ifndef GOBJECT_H
#define GOBJECT_H
#include "render/textureprovider.h"

class GObject
{
public:
    virtual ~GObject();
    virtual SDL_Texture * getTexture() = 0;

    //geometry func
    virtual int getX() { return m_x; }
    virtual int getY() { return m_y; }
    virtual int getH() { return m_height; }
    virtual int getW() { return m_width; }


    virtual void setX(int x) { m_x = x;}
    virtual void setY(int y) { m_y = y;}
    virtual void setH(int height) { m_height = height;}
    virtual void setW(int width) { m_width = width;}

    virtual void move(int xDiff, int yDiff) = 0;


protected:
    GObject();

    //coordinates and sizes
    int m_x;
    int m_y;
    int m_width;
    int m_height;

    SDL_Texture * m_texture;
    ObjectsType m_type;
};

#endif // GOBJECT_H
