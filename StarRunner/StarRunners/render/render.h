#ifndef RENDER_H
#define RENDER_H

#include"SDL2/SDL.h"
#include "iostream"
#include "objectController/objectcontroller.h"

class Camera;

class Render
{
public:
    Render();
    ~Render();
    bool init();
    void renderScreen();


private:
    SDL_Window * m_window;
    SDL_Renderer * m_rend;
    Camera * m_camera;

    TextureProvider * m_textureProvider;

    void drawSurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend);
    void drawBackground();

    ObjectController* m_objController;
    list<GObject*>* m_olist;


    //background data:
    //
    int m_graphFWidth, m_graphFHeight,
        m_fieldGapX, m_fieldGapY;
    GObject* m_backGround;
    GObject* m_player;
};



/****************************************************************************
Camera class!
****************************************************************************/
class Camera
{
public:
    Camera(GObject * target, int gapX, int gapY);
    ~Camera();
    int x();
    int y();

protected:
    GObject * m_target;
    int m_shiftX, m_shiftY;
};

#endif // RENDER_H
