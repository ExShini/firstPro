#ifndef GOBJECT_H
#define GOBJECT_H
#include "render/textureprovider.h"

class GObject
{
public:
    virtual ~GObject();
    virtual SDL_Texture * getTexture() = 0;

protected:
    GObject();
    SDL_Texture * m_texture;
    ObjectsType m_type;
};


typedef struct
{
    GObject * m_head;
    GObject * m_tail;
} GOQueue;

#endif // GOBJECT_H
