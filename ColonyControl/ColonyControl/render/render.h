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

    void drawSurface(int x, int y, FrameController* fcontroller, SDL_Renderer* rend);
    void drawBackground();
    void drawObjects();
    void checkCordinats(int* x, int* y, int* w, int* h);

    ObjectController* m_objController;
    PlanetMap* m_plMap;


    //background data:
    //
    int m_graphFWidth, m_graphFHeight,
        m_fieldGapX, m_fieldGapY;
    GObject* m_backGround;
    GObject* m_cameraObj;

    int m_widthInFields, m_heightInFields;
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
