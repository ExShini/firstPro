#include "textprovider.h"

TextProvider * TextProvider::m_instance = new TextProvider();

TextProvider::TextProvider()
{
}

bool TextProvider::Init()
{
    if (TTF_Init() != 0)
    {
        cout << "TextProvider::Init TTF_Init fail: " << SDL_GetError() << endl ;
        return false;
    }

    return true;
}

void TextProvider::setRenderer(SDL_Renderer *renderer)
{
    m_renderer = renderer;
}

TextProvider * TextProvider::getInstance()
{
    return m_instance;
}

SDL_Texture * TextProvider::getTextuteByText(string &text, TTF_Font* font, SDL_Color color)
{
    SDL_Surface *surf = TTF_RenderText_Blended(font, text.c_str(), color);
    if(surf == NULL)
    {
        cout << "TextProvider::getTextuteByText TTF_RenderText_Blended fail: " << SDL_GetError() << endl ;
        return NULL;
    }

    SDL_Texture * texture = SDL_CreateTextureFromSurface(m_renderer, surf);
    if (texture == NULL){
        cout << "TextProvider::getTextuteByText SDL_CreateTextureFromSurface fail: " << SDL_GetError() << endl ;
        return NULL;
    }
    //Clean up the surface and font
    SDL_FreeSurface(surf);

    return texture;
}
