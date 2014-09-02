#ifndef TEXTUREPROVIDER_H
#define TEXTUREPROVIDER_H

#include "string"
#include "map"
#include "enums/textures_paths.h"
#include "enums/objects.h"
#include "framecontroller.h"

using namespace std;

class TextureProvider
{
public:
    static TextureProvider * getInstance();
    SDL_Texture* getTexture(ObjectsType objectType);
    void setRender(SDL_Renderer * rend);

protected:
    TextureProvider();
    ~TextureProvider();

    SDL_Renderer* m_rend;
    SDL_Texture* loadImage(std::string file);
    void initTextureProvider();

    static TextureProvider * m_instance;
    map< ObjectsType, SDL_Texture* > m_textures;


};

#endif // TEXTUREPROVIDER_H
