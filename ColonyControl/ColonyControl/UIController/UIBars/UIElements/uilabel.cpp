#include "uilabel.h"
#include <sstream>

#ifdef WIN32
#include "../../../render/textframecontroller.h"
#else
#include "render/textframecontroller.h"
#endif

using namespace std;

UILabel::UILabel():
    GObject()
{
    m_type = t_UILabel;
    m_fcontroller = new TextFrameController();
}


bool UILabel::setDataTo(unsigned int position, int number)
{
    if (m_labelText.size() > position)
    {
        std::ostringstream stm;
        stm << number;
        m_labelText[position] = stm.str();
        return true;
    }
    cout << "setDataTo(unsigned int position, int number) failure" << endl ;
    return false;
}

bool UILabel::setDataTo(unsigned int position, string &text)
{
    if (m_labelText.size() > position)
    {
        m_labelText[position] = text;
        return true;
    }
    cout << "setDataTo(unsigned int position, string &text) failure" << endl ;
    return false;
}

void UILabel::addData(int number)
{
    std::ostringstream stm;
    stm << number;
    m_labelText.push_back(stm.str());
}

void UILabel::addData(string & text)
{
    m_labelText.push_back(text);
}

void UILabel::clearLabel()
{
    m_labelText.clear();
}

void UILabel::applyChanges()
{
    TextFrameController* tc = static_cast<TextFrameController*>(m_fcontroller);
    tc->ClearText();

    int count = m_labelText.size();

    for(int i = 0; i < count ; i++)
    {
        string text = m_labelText[i];
        tc->AddText(text);
    }
    tc->ApplyChanges();
}
