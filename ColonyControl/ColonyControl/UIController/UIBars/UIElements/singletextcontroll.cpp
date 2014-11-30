#include "singletextcontroll.h"

#ifdef WIN32
#include "../../../render/textframecontroller.h"
#else
#include "render/textframecontroller.h"
#endif



SingleTextControll::SingleTextControll():
    GObject()
{
    m_type = t_singleTextController;
    m_fcontroller = new TextFrameController();
}

void SingleTextControll::setData(int number)
{
    TextFrameController * tc = static_cast<TextFrameController*>(m_fcontroller);
    tc->ClearText();
    tc->AddText(number);
    tc->ApplyChanges();
}

void SingleTextControll::setData(string &text)
{
    TextFrameController * tc = static_cast<TextFrameController*>(m_fcontroller);
    tc->ClearText();
    tc->AddText(text);
    tc->ApplyChanges();
}
