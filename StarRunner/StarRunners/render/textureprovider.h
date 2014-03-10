#ifndef TEXTUREPROVIDER_H
#define TEXTUREPROVIDER_H

#include "map"
#include "SDL2/SDL.h"
#include "enums/textures_paths.h"
#include "enums/objects.h"

using namespace std;

class TextureProvider
{
public:
    static TextureProvider * getInstance();
    SDL_Texture* getTexture(ObjectsType objectType);

protected:
    TextureProvider();
    ~TextureProvider();

    SDL_Texture* loadImage(std::string file);

    static TextureProvider * m_instance;
    map< ObjectsType, SDL_Texture* > m_textures;


};

#endif // TEXTUREPROVIDER_H
