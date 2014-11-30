#ifndef TEXTFRAMECONTROLLER_H
#define TEXTFRAMECONTROLLER_H
#include "iostream"
#include "string"
#include "SDL2/SDL_ttf.h"

#include "framecontroller.h"


using namespace std;
class TextFrameController: public FrameController
{
public:
    TextFrameController();
    ~TextFrameController();

    void AddText(string& text);
    void AddText(int number);
    void ClearText();
    void ApplyChanges();

protected:
    TTF_Font* m_font;
    string m_text;
    SDL_Color m_color;
    SDL_Renderer * m_renderer;
};

#endif // TEXTFRAMECONTROLLER_H
