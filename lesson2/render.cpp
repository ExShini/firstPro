#include "render.h"
#include "enum.h"
#include "stdio.h"


/*************************************
FUNC: Render()
DESC: constructor
*************************************/
Render::Render(AEQueue *Queue):
    m_window(NULL),
    m_rend(NULL),
    m_back(NULL),
    m_queue(NULL)
{
    m_queue = Queue;
}

/*************************************
FUNC: ~Render()
DESC: destructor
*************************************/
Render::~Render()
{
    SDL_DestroyTexture(m_back);
    SDL_DestroyRenderer(m_rend);
    SDL_DestroyWindow(m_window);
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


    //init textures
    m_aliveTexture = loadImage(ALIVE_ELEMENT);
    m_back = loadImage(BACKGROUND);

    if (m_window && m_rend && m_aliveTexture && m_back)
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
    loadBackGround();

    if (m_aliveTexture != NULL)
    {
        AliveElement * el = m_queue->m_head;
        // draw all element from queue
        while ( el != NULL )
        {
            drawSurface( el->getX() * SIZE_OF_FIELD_EL , el->getY() * SIZE_OF_FIELD_EL , m_aliveTexture, m_rend);
            el = el->getNextEl();
        }
    }

    SDL_RenderPresent(m_rend);
}


/*************************************
FUNC: loadImage()
DESC: prepare texture from bmp file which "file" adress
*************************************/
SDL_Texture* Render::loadImage(std::string file)
{
    SDL_Surface *loadedImage = NULL;
    SDL_Texture *texture = NULL;

    loadedImage = SDL_LoadBMP(file.c_str());
    if (loadedImage != NULL)
    {
        texture = SDL_CreateTextureFromSurface(m_rend, loadedImage);
        SDL_FreeSurface(loadedImage);
    }
    else
    {
        std::cout << SDL_GetError() << std::endl;
    }
    return texture;
}


/*************************************
FUNC: loadBackGround()
DESC: draw background image
*************************************/
bool Render::loadBackGround()
{
    if (m_back == NULL)
    {
        return false;
    }
    drawSurface( 0, 0, m_back, m_rend);

    return true;
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
