#ifndef RENDER_H
#define RENDER_H

#ifdef WIN32
#include "../ColonyControlWin/stdafx.h"
#include"SDL.h"
#include "../objectController/objectcontroller.h"
#include "../gameProcessor/unitcontroller.h"
#include "../UIController/uicontroller.h"
#else
#include"SDL2/SDL.h"
#include "objectController/objectcontroller.h"
#include "gameProcessor/unitcontroller.h"
#include "UIController/uicontroller.h"
#endif

#include "textprovider.h"


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
    TextProvider * m_textProvider;

    void drawSurface(int x, int y, FrameController* fcontroller, SDL_Renderer* rend);
    void drawSurfaceEx(int x, int y, int angle, FrameController* fcontroller, SDL_Renderer* rend);
    void drawBackground();
    void drawObjects();
    void drawUnits();
    void drawUI();

    void checkCordinats(int* x, int* y, int* w, int* h);

    ObjectController* m_objController;
    UnitController* m_unitController;
    UIController* m_UIController;
    PlanetMap* m_plMap;


    //background data:
    //
    int m_graphFWidth, m_graphFHeight,
        m_fieldGapX, m_fieldGapY;
    GObject* m_backGround;
    GObject* m_cameraObj;
    GObject* m_targetObj;

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
