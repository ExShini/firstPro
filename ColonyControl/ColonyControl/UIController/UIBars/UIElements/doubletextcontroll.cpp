#include <sstream>
#include "doubletextcontroll.h"

#ifdef WIN32
#include "../../../render/textframecontroller.h"
#else
#include "render/textframecontroller.h"
#endif

DoubleTextControll::DoubleTextControll():
    GObject()
{
    m_type = t_singleTextController;
    m_fcontroller = new TextFrameController();
}

void DoubleTextControll::setFirstData(int number)
{
    std::ostringstream stm;
    stm << number;
    m_first = stm.str();
}

void DoubleTextControll::setFirstData(string &text)
{
    m_first = text;
}

void DoubleTextControll::setSecondData(int number)
{
    std::ostringstream stm;
    stm << number;
    m_second = stm.str();
}

void DoubleTextControll::setSecondData(string &text)
{
    m_second = text;
}


void DoubleTextControll::setSeparator(string & sep)
{
    m_sep = sep;
}

void DoubleTextControll::ApplyChange()
{
    string resText = m_first + m_sep + m_second;
    TextFrameController * tc = static_cast<TextFrameController*>(m_fcontroller);
    tc->ClearText();
    tc->AddText(resText);
    tc->ApplyChanges();
}
