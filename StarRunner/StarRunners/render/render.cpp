#include "render.h"
#include "enums/enums.h"
#include "textureprovider.h"

#include "stdio.h"



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
    m_window = SDL_CreateWindow ("Main Window", X_COR_MAIN_WINDOW, Y_COR_MAIN_WINDOW, WIDTH_MAIN_WINDOW, HEIGHT_MAIN_WINDOW, SDL_WINDOW_SHOWN);
    m_rend = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_RenderClear(m_rend);

    //set sdl_render to textProvider
    TextureProvider::getInstance()->setRender(m_rend);

    //set ObjectController to render
    m_objController = ObjectController::getInstance();
    m_objController->init();
    m_olist = m_objController->getObjectList();

    //init camera
    m_camera = new Camera(m_objController->getPlayer());

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
    if (!m_olist->empty())
    {
        list<GObject*>::iterator iter = m_olist->begin();

        for (; iter != m_olist->end(); iter++)
        {
            GObject* obj = /*(GObject*)*/*iter;
            drawSurface( obj->getX() - m_camera->x(),
                         obj->getY() - m_camera->y(),
                         obj->getTexture(), m_rend);
        }
    }
    else
    {
        cout << "List is empty!" << endl;
    }

    SDL_RenderPresent(m_rend);
}


/*************************************
FUNC: drawSurface()
DESC: draw current texture in (x,y) position
*************************************/
void Render::drawSurface(int x, int y, SDL_Texture *tex, SDL_Renderer *rend){
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
    SDL_RenderCopy(rend, tex, NULL, &pos);
}


/****************************************************************************
Camera class!
****************************************************************************/
Camera::Camera(GObject *target)
{
    m_target = target;
    m_shiftX = WIDTH_MAIN_WINDOW /2 - m_target->getW() /2;
    m_shiftY = HEIGHT_MAIN_WINDOW /2 - m_target->getY() /2;
}

int Camera::x()
{
    return m_target->getX() - m_shiftX;
}

int Camera::y()
{
    return m_target->getY() - m_shiftY;
}

Camera::~Camera()
{
}
