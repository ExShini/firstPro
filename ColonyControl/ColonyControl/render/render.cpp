#include "render.h"

#ifdef WIN32
#include "../enums/enums.h"
#include "../ColonyControlWin/stdafx.h"
#else
#include "enums/enums.h"
#endif

#include "textureprovider.h"

#include "stdio.h"

#include "iostream"
using namespace std;


/*************************************
FUNC: Render()
DESC: constructor
*************************************/
Render::Render():
    m_window(NULL),
    m_rend(NULL),
    m_camera(NULL)
{
    m_textureProvider = TextureProvider::getInstance();
    m_widthInFields = WIDTH_MAIN_WINDOW / FIELD_SIZE;
    m_heightInFields = HEIGHT_MAIN_WINDOW / FIELD_SIZE;
}

/*************************************
FUNC: ~Render()
DESC: destructor
*************************************/
Render::~Render()
{
    SDL_DestroyRenderer(m_rend);
    SDL_DestroyWindow(m_window);
}

/*************************************
FUNC: init()
DESC: initialize and prepare render's members
*************************************/
bool Render::init()
{
    //Craeta new main window
    m_window = SDL_CreateWindow ("Main Window",
                                 SDL_WINDOWPOS_UNDEFINED,
                                 SDL_WINDOWPOS_UNDEFINED,
                                 WIDTH_MAIN_WINDOW,
                                 HEIGHT_MAIN_WINDOW,
                                 SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP);
    m_rend = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_RenderClear(m_rend);
    SDL_RenderSetLogicalSize(m_rend, WIDTH_MAIN_WINDOW, HEIGHT_MAIN_WINDOW);

    //set resolution for displaing
    //get current display mode
    SDL_DisplayMode * current = new SDL_DisplayMode();
    for(int i = 0; i < SDL_GetNumVideoDisplays(); ++i)
    {
        int should_be_zero = SDL_GetCurrentDisplayMode(i, current);

        if(should_be_zero != 0)
        {
            // In case of error...
            printf("Could not get display mode for video display #%d: %s", i, SDL_GetError());
        }
        else
            break;
    }




    //set sdl_render to textProvider
    TextureProvider::getInstance()->setRender(m_rend);

    //set ObjectController to render
    m_objController = ObjectController::getInstance();
    m_objController->init();
    m_plMap = m_objController->getPlanetMap();

    //set UnitController to render
    m_unitController =  UnitController::getInstance();

    //set UIController to render
    m_UIController = UIController::getInstance();

    //set backGround object to render
    m_backGround = m_objController->getBackGround();

    //set parameters for background drawing
    m_graphFWidth = FIELD_SIZE * MAP_WIDTH + WIDTH_MAIN_WINDOW;
    m_graphFHeight = FIELD_SIZE * MAP_HEIGHT + HEIGHT_MAIN_WINDOW;
    m_fieldGapX = WIDTH_MAIN_WINDOW / 2;
    m_fieldGapY = HEIGHT_MAIN_WINDOW / 2;

    //init camera
    m_cameraObj = m_objController->getCamera();
    m_camera = new Camera(m_cameraObj, m_fieldGapX, m_fieldGapY);

    //check status
    if (m_window && m_rend)
    {
        return true;
    }
    else
    {
        printf("render init error");
        return false;
    }
}

/*************************************
FUNC: renderScreen()
DESC: draw all element from map for current step
*************************************/
void Render::renderScreen()
{
    //draw background
    drawBackground();

    //draw objects
    drawObjects();

    //draw all units
    drawUnits();

    //drow all UIElements
    drawUI();

    SDL_RenderPresent(m_rend);
}

/*************************************
FUNC: drawUI()
DESC: draw user interface elements
*************************************/
void Render::drawUI()
{
    vector<UIElement*> elements = m_UIController->getUIElements();

    vector<UIElement*>::iterator iter = elements.begin();
    vector<UIElement*>::iterator end = elements.end();

    for(; iter != end ; iter++)
    {
        UIElement* element = *iter;
        drawSurface( element->getX(), element->getY(), element->getFController(), m_rend);
    }
}

/*************************************
FUNC: drawObjects()
DESC: draw all game objects (sectors, settlers and etc)
*************************************/
void Render::drawObjects()
{
    int xcor, ycor, w, h;

    xcor = m_cameraObj->getX() - (m_widthInFields >> 1) - 1;
    ycor = m_cameraObj->getY() - (m_heightInFields >> 1) - 1;
    w = xcor + m_widthInFields + 2;
    h = ycor + m_heightInFields + 2;

    checkCordinats(&xcor, &ycor, &w, &h);

    for (int level = SECTOR_LEVEL; level < NUM_LEVELS; level++)
    {

        Layer* curLayer = m_plMap->objects[level];

        for (int i = xcor; i < w; i++)
        {
            for (int j = ycor; j < h; j++)
            {
                GObject* obj = curLayer->lMap[i][j];
                if (obj == NULL)
                    continue;

                drawSurface( (obj->getX() MULTIPLY_FS) - m_camera->x() + m_fieldGapX,
                             (obj->getY() MULTIPLY_FS) - m_camera->y() + m_fieldGapY,
                             obj->getFController(), m_rend);
            }
        }
    }
}


/*************************************
FUNC: drawUnits()
DESC: draw all units
*************************************/
void Render::drawUnits()
{
    list<Unit*>* units = m_unitController->getUnitList();

    list<Unit*>::iterator iterator = units->begin();
    list<Unit*>::iterator end = units->end();

    for(; iterator != end; iterator++)
    {
        Unit* unit = (Unit*)(*iterator);
        drawSurfaceEx( unit->getX() - m_camera->x() + m_fieldGapX,
                       unit->getY() - m_camera->y() + m_fieldGapY,
                       unit->getAngle(),
                       unit->getFrameController(), m_rend);
    }

}

/*************************************
FUNC: checkCordinats()
DESC: check field coordinate for drawing
*************************************/
void Render::checkCordinats(int *x, int *y, int *w, int *h)
{
    if(*x < 0)
    {
        *x = 0;
    }

    if(*y < 0)
    {
        *y = 0;
    }

    if(*w > MAP_WIDTH)
    {
        *w = MAP_WIDTH;
    }

    if(*h > MAP_HEIGHT)
    {
        *h = MAP_HEIGHT;
    }
}

/*************************************
FUNC: drawSurface()
DESC: draw current texture in (x,y) position
*************************************/
void Render::drawSurface(int x, int y, FrameController* fcontroller, SDL_Renderer* rend)
{
    SDL_Rect target;
    target.x = x;
    target.y = y;

    const SDL_Rect& src = fcontroller->getSrcRect();
    target.h = src.h;
    target.w = src.w;

    SDL_Texture* tex = fcontroller->getTexture();

    SDL_RenderCopy(rend, tex, &src, &target);
}

/*************************************
FUNC: drawSurface()
DESC: draw current texture in (x,y) position
*************************************/
void Render::drawSurfaceEx(int x, int y, int angle, FrameController* fcontroller, SDL_Renderer* rend)
{
    SDL_Rect target;
    target.x = x;
    target.y = y;

    const SDL_Rect& src = fcontroller->getSrcRect();
    target.h = src.h;
    target.w = src.w;

    SDL_Texture* tex = fcontroller->getTexture();

    SDL_RenderCopyEx(rend, tex, &src, &target, angle, NULL, SDL_FLIP_NONE);
}

/*************************************
FUNC: drawBackground()
DESC: draw background picture
*************************************/
void Render::drawBackground()
{
    int x = -((( m_cameraObj->getX() M_ACCURACY_FACTOR) PART_OF_MAP_W )
              * ( m_backGround->getW() - WIDTH_MAIN_WINDOW ) ) D_ACCURACY_FACTOR;

    int y = -((( m_cameraObj->getY() M_ACCURACY_FACTOR) PART_OF_MAP_H )
              * (m_backGround->getH() - HEIGHT_MAIN_WINDOW) ) D_ACCURACY_FACTOR;

    drawSurface( x, y, m_backGround->getFController(), m_rend);
}


/****************************************************************************
Camera class!
****************************************************************************/
Camera::Camera(GObject *target, int gapX, int gapY)
{
    m_target = target;
    m_shiftX = WIDTH_MAIN_WINDOW /2 - (m_target->getW() MULTIPLY_FS) /2 - gapX;
    m_shiftY = HEIGHT_MAIN_WINDOW /2 - (m_target->getH() MULTIPLY_FS) /2 - gapY;
}

int Camera::x()
{
    return (m_target->getX() MULTIPLY_FS) - m_shiftX;
}

int Camera::y()
{
    return (m_target->getY() MULTIPLY_FS) - m_shiftY;
}

Camera::~Camera()
{
}
