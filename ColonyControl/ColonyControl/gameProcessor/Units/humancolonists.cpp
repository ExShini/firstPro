#include "cmath"
#include "iostream"
#include "humancolonists.h"

#ifdef WIN32
#include "../../enums/Units/humanUnits.h"
#include "../../enums/gameProcessingSettings.h"
#include "../../enums/gui_enums.h"
#else
#include "enums/Units/humanUnits.h"
#include "enums/gameProcessingSettings.h"
#include "enums/gui_enums.h"
#include "gameProcessor/gameprocessor.h"
#endif

using namespace std;

HumanColonists::HumanColonists(int startSecX, int startSecY, int tarSecX, int tarSecY, int colonists):
    m_stX(startSecX),
    m_stY(startSecY),
    m_tgX(tarSecX),
    m_tgY(tarSecY),
    m_colonists(colonists)
{
    m_active = true;
    m_x = startSecX * FIELD_SIZE;
    m_y = startSecY * FIELD_SIZE;

    Vec a;
    a.X = tarSecX - startSecX;
    a.Y = tarSecY - startSecY;

    m_steps = (sqrt(pow(a.X, 2) + pow(a.Y, 2)) * UNIT_PROC_RATE) / HUM_COLONIST_SHUTL_SPEED;

    if(a.X != 0 && a.Y != 0)
    {
        Vec b;
        b.X = tarSecX - startSecX;
        //b.Y = 0;

        //calc angle
        m_alpha = acos((double)(a.X * b.X /*+ a.Y * b.Y*/) / (double)(sqrt(pow(a.X, 2) + pow(a.Y, 2)) * b.X ));
        if(a.X > 0)
            m_alpha = 360 - m_alpha;

        //TODO: add speed calculating!!!
    }
    else
    {
        if (a.X > 0)
        {
            m_alpha = 0;
            m_xSpeed = (HUM_COLONIST_SHUTL_SPEED * FIELD_SIZE) / UNIT_PROC_RATE;
            m_ySpeed = 0;
        }
        else if(a.X < 0)
        {
            m_alpha = 180;
            m_xSpeed = -(HUM_COLONIST_SHUTL_SPEED * FIELD_SIZE) / UNIT_PROC_RATE;
            m_ySpeed = 0;
        }
        else if(a.Y > 0)
        {
            m_alpha = 90;
            m_xSpeed = 0;
            m_ySpeed = (HUM_COLONIST_SHUTL_SPEED * FIELD_SIZE) / UNIT_PROC_RATE;
        }
        else if(a.Y < 0)
        {
            m_alpha = 270;
            m_xSpeed = 0;
            m_ySpeed = -(HUM_COLONIST_SHUTL_SPEED * FIELD_SIZE) / UNIT_PROC_RATE;
        }
    }

    //set graphic settings
    m_fcontroller = new FrameController(
                TextureProvider::getInstance()->getTexture(t_HumanFighter), true);
}

void HumanColonists::process()
{
    m_x += m_xSpeed;
    m_y += m_ySpeed;

    m_steps--;
    if(m_steps <= 0)
    {
        //colonize target sector
        GameProcessor::getInstance()->tryColonize(m_tgX, m_tgY, m_colonists);
        m_active = false;
    }

}

