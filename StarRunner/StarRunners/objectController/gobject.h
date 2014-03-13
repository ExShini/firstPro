#ifndef GOBJECT_H
#define GOBJECT_H
#include "render/textureprovider.h"

class GObject
{
public:
    GObject();
    virtual ~GObject();
    virtual SDL_Texture * getTexture() = 0;

    //geometry func
    virtual int getX() = 0;
    virtual int getY() = 0;
    virtual int getH() = 0;
    virtual int getW() = 0;


    virtual int setX(int x) { m_x = x;}
    virtual int setY(int y) { m_y = y;}
    virtual int setH(int height) { m_height = height;}
    virtual int setW(int width) { m_width = width;}


protected:
    SDL_Texture * m_texture;
    ObjectsType m_type;

    //coordinates and sizes
    int m_x;
    int m_y;
    int m_width;
    int m_height;
};

#endif // GOBJECT_H
