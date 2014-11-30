#include <sstream>
#include "textframecontroller.h"

#ifdef WIN32
#include "../enums/textSetting.h"
#else
#include "enums/textSetting.h"
#endif

#include "textprovider.h"

/*************************************
FUNC: FrameController(SDL_Texture* texture, bool fullTexture)
DESC: constructor
*************************************/
TextFrameController::TextFrameController():
    FrameController(true)
{
    m_font = TTF_OpenFont(FontPath, FontSize);
    if (m_font == NULL){
        cout << "TextFrameController TTF_OpenFont fail: " << SDL_GetError() << endl ;
        return;
    }

    // some blue color E3F2FD
    m_color.a = 255;
    m_color.r = 0xE3;
    m_color.g = 0xF2;
    m_color.b = 0xFD;
}

TextFrameController::~TextFrameController()
{
    TTF_CloseFont(m_font);
}

void TextFrameController::AddText(string &text)
{
    m_text = m_text + text;
}

void TextFrameController::AddText(int number)
{
    std::ostringstream stm;
    stm << number;
    m_text = m_text + stm.str();
}

void TextFrameController::ClearText()
{
    m_text.clear();
}

void TextFrameController::ApplyChanges()
{
    SDL_DestroyTexture(m_texture);
    m_texture = TextProvider::getInstance()->getTextuteByText(m_text, m_font, m_color);
}
