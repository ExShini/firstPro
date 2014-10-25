#include "cmath"
#include "iostream"
#include "humancolonists.h"

#ifdef WIN32
#include "../../enums/Units/humanUnits.h"
#include "../../enums/gameProcessingSettings.h"
#include "../../enums/gui_enums.h"
#include "../playercontroller.h"
#else
#include "enums/Units/humanUnits.h"
#include "enums/gameProcessingSettings.h"
#include "enums/gui_enums.h"
#include "gameProcessor/playercontroller.h"
#endif

#include "UnitProcessors/humshutleimmigrateproc.h"
#include "UnitProcessors/humshutleemigrationproc.h"
#include "UnitProcessors/humshutlereturntobaseproc.h"

using namespace std;

/*************************************
FUNC: HumanColonists()
DESC: constructor
*************************************/
HumanColonists::HumanColonists(GObject* base, GObject *target, int playerID):
    Unit(playerID),
    m_shutlState(findEmigrants)
{
    m_active = true;
    m_base = base;

    m_x = base->getX() MULTIPLY_FS;
    m_y = base->getY() MULTIPLY_FS;

    cout << "HumanColonists 2. Position: " << m_x << ":" << m_y << endl;
    //set direction to first target
    setDirection(target);


    //set graphic settings
    m_fcontroller = new FrameController(
                TextureProvider::getInstance()->getTexture(t_HumanFighter), true);

    m_processors[findEmigrants] = new HumShutleEmigrationProc(this);
    m_processors[moveImmigrants] = new HumShutleImmigrateProc(this);
    m_processors[returnToBase] = new HumShutleReturnToBaseProc(this);
}

/*************************************
FUNC: HumanColonists()
DESC: destructor
*************************************/
HumanColonists::~HumanColonists()
{
    delete m_processors[findEmigrants];
    delete m_processors[moveImmigrants];
    delete m_processors[returnToBase];
}

/*************************************
FUNC: SetDirection(Settlement *target)
DESC: Set direction to target sector
*************************************/
void HumanColonists::setDirection(GObject *target)
{
    m_tx = target->getX();
    m_ty = target->getY();
    m_xCap = 0;
    m_yCap = 0;

    Vec a;
    a.X = m_tx - (m_x DIVIDE_FS);
    a.Y = m_ty - (m_y DIVIDE_FS);

    cout << "setDirection to: " << target->getX() << ":" << target->getY()
         << " from " << (m_x DIVIDE_FS) << ":" << ((m_y DIVIDE_FS)) << endl;

    if(a.X == 0 && a.Y == 0)
    {
        m_steps = 0;
        m_alpha = 0;
        m_xSpeed = 0;
        m_ySpeed = 0;

        return;
    }
    else
    {
        m_steps = (sqrt(pow(a.X, 2) + pow(a.Y, 2)) * UNIT_PROC_RATE) / HUM_SHUTL_TRANSPORT_SPEED;
    }


    if(a.X != 0)
    {
        //calc angle
        double radAng = atan((double)(a.Y)/((double)a.X));
        m_alpha = radAng * RAD1;
    }
    else if (a.Y >= 0)
    {
        m_alpha = 90;
    }
    else if (a.Y < 0)
    {
        m_alpha = 270;
    }

    m_xSpeed = ((a.X * FIELD_SIZE) * ACCURACY_SPEED_FACTOR) / m_steps;
    m_ySpeed = ((a.Y * FIELD_SIZE) * ACCURACY_SPEED_FACTOR) / m_steps;


    if(a.X < 0)
    {
        m_alpha += 180;
    }

    cout << "!!! setDirection NOT NORMAL: " << m_xSpeed << " yspeed" << m_ySpeed << endl;
    cout << "!!! alpha: " << m_alpha << " steps " << m_steps << endl;
    cout << "!!! A: " << a.X << ":" << a.Y << endl;


    cout << "setDirection end xspeed: " << m_xSpeed << " yspeed" << m_ySpeed << endl;
}


/*************************************
FUNC: process()
DESC: main process func
*************************************/
void HumanColonists::process()
{
    m_xCap += m_xSpeed;
    m_yCap += m_ySpeed;

    m_x += m_xCap / ACCURACY_SPEED_FACTOR;
    m_y += m_yCap / ACCURACY_SPEED_FACTOR;

    m_xCap = m_xCap % ACCURACY_SPEED_FACTOR;
    m_yCap = m_yCap % ACCURACY_SPEED_FACTOR;

    m_steps--;

    m_processors[m_shutlState]->process();
}

