#include "textureprovider.h"

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
    m_textures[t_StationBlock] = loadImage(p_STATIONBLOCK);
    m_textures[t_Wall] = loadImage(p_WALL);
    m_textures[t_TestObject1] = loadImage(p_TEST_OBJ1);
    m_textures[t_TestObject2] = loadImage(p_TEST_OBJ2);
    m_textures[t_Floor] = loadImage(p_FLOOR);
    m_textures[t_Door] = loadImage(p_DOOR);
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
    SDL_Surface *loadedImage = NULL;
    SDL_Texture *texture = NULL;

    loadedImage = SDL_LoadBMP(file.c_str());
    loadedImage->format->Amask = 0xFF0000;
    if (loadedImage != NULL)
    {
        texture = SDL_CreateTextureFromSurface(m_rend, loadedImage);
        SDL_FreeSurface(loadedImage);
    }
    else
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
