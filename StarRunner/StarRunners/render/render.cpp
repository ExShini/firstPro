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
    m_rend(NULL)
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

    m_objController = ObjectController::getInstance();
    m_olist = m_objController->getObjectList();
}

/*************************************
FUNC: init()
DESC: initialize and prepare render's members
*************************************/
bool Render::init()
{

    m_window = SDL_CreateWindow ("Main Window", X_COR_MAIN_WINDOW, Y_COR_MAIN_WINDOW, WIDTH_MAIN_WINDOW, HEIGHT_MAIN_WINDOW, SDL_WINDOW_SHOWN);
    m_rend = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_RenderClear(m_rend);

    //set render to textProvider
    TextureProvider::getInstance()->setRender(m_rend);


//    //init textures
//    SDL_Texture * objText = m_textureProvider->getTexture(TestObject1);
//    SDL_Texture * back = m_textureProvider->getTexture(BACKGROUND);

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
    list<GObject*>::iterator iter = m_olist->begin();

    for (; iter != m_olist->end(); iter++)
    {
        GObject* obj = /*(GObject*)*/*iter;
        drawSurface( obj->getX(), obj->getY(), obj->getTexture(), m_rend);
    }

//    if (m_aliveTexture != NULL)
//    {
//        AliveElement * el = m_queue->m_head;
//        // draw all element from queue
//        while ( el != NULL )
//        {
//            drawSurface( el->getX() * SIZE_OF_FIELD_EL , el->getY() * SIZE_OF_FIELD_EL , m_aliveTexture, m_rend);
//            el = el->getNextEl();
//        }
//    }

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
