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
    m_window = SDL_CreateWindow ("Main Window",
                                 SDL_WINDOWPOS_UNDEFINED,
                                 SDL_WINDOWPOS_UNDEFINED,
                                 0,
                                 0,
                                 SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN);
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
    m_olist = m_objController->getObjectList();

    //set backGround object to render
    m_backGround = m_objController->getBackGround();

    //set parameters for background drawing
    m_graphFWidth = FIELD_SIZE * MAP_WIDTH + WIDTH_MAIN_WINDOW;
    m_graphFHeight = FIELD_SIZE * MAP_HEIGHT + HEIGHT_MAIN_WINDOW;
    m_fieldGapX = WIDTH_MAIN_WINDOW / 2;
    m_fieldGapY = HEIGHT_MAIN_WINDOW / 2;

    //init camera
    m_player = m_objController->getPlayer();
    m_camera = new Camera(m_player, m_fieldGapX, m_fieldGapY);

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

    if (!m_olist->empty())
    {
        list<GObject*>::iterator iter = m_olist->begin();

        for (; iter != m_olist->end(); iter++)
        {
            GObject* obj = /*(GObject*)*/*iter;
            drawSurface( (obj->getX() MULTIPLY_FS) - m_camera->x() + m_fieldGapX,
                         (obj->getY() MULTIPLY_FS) - m_camera->y() + m_fieldGapY,
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

void Render::drawBackground()
{
    int x = -((( m_player->getX() M_ACCURACY_FACTOR) PART_OF_MAP_W )
              * ( m_backGround->getW() - WIDTH_MAIN_WINDOW ) ) D_ACCURACY_FACTOR;

    int y = -((( m_player->getY() M_ACCURACY_FACTOR) PART_OF_MAP_H )
              * (m_backGround->getH() - HEIGHT_MAIN_WINDOW) ) D_ACCURACY_FACTOR;

    drawSurface( x, y, m_backGround->getTexture(), m_rend);
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
