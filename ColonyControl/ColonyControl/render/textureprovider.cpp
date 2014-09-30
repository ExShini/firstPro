#include "textureprovider.h"
#include "SDL2/SDL_image.h"
#include "iostream"

TextureProvider * TextureProvider::m_instance = new TextureProvider();

/*************************************
FUNC: TextureProvider()
DESC: constructor
*************************************/
TextureProvider::TextureProvider()
{

}

/*************************************
FUNC: setRender()
DESC: set render for textureProvider and initialize texture loading
*************************************/
void TextureProvider::setRender(SDL_Renderer *rend)
{
    m_rend = rend;
    initTextureProvider();
}

TextureProvider::~TextureProvider()
{
    map < ObjectsType, SDL_Texture* >::iterator curr;

    for (curr = m_textures.begin(); curr != m_textures.end(); curr++)
    {
        if ((*curr).second != NULL)
            SDL_DestroyTexture((*curr).second);
    }
}

/*************************************
FUNC: initTextureProvider()
DESC: load and prepare all textures
*************************************/
void TextureProvider::initTextureProvider()
{
    //initialize textures for all objects type
    m_textures[t_BACKGROUND] = loadImage(p_BACKGROUND);
    m_textures[t_CameraObject] = loadImage(p_TEST_OBJ1);
    m_textures[t_Sector] = loadImage(p_Sector);
    m_textures[t_HumanSettlers] = loadImage(p_HumanSettlers);
    m_textures[t_LavaMount] = loadImage(p_LavaMount);
    m_textures[t_Lava] = loadImage(p_Lava);
}

/*************************************
FUNC: getInstance()
DESC: very simple singleton
*************************************/
TextureProvider* TextureProvider::getInstance()
{
    return m_instance;
}

/*************************************
FUNC: loadImage()
DESC: prepare texture from bmp-file where "file" - local adress
*************************************/
SDL_Texture* TextureProvider::loadImage(std::string file)
{
    //SDL_Surface *loadedImage = NULL;
    SDL_Texture *texture = NULL;

    texture = IMG_LoadTexture(m_rend, file.c_str());

    if(texture == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
    }

    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    SDL_SetTextureAlphaMod(texture, 255);

    return texture;
}

/*************************************
FUNC: getTexture()
DESC: return SDL_Texture* by objectType
*************************************/
SDL_Texture* TextureProvider::getTexture(ObjectsType objectType)
{
    return m_textures[objectType];
}
