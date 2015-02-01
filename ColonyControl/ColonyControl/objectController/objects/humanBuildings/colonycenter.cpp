#include "iostream"
#include "colonycenter.h"

#ifdef WIN32
#include "../../../enums/Units/humanUnits.h"
#include "../../../enums/gameProcessingSettings.h"
#include "../../../gameProcessor/playercontroller.h"
#include "../../../gameProcessor/Units/humancolonists.h"
#else
#include "enums/Units/humanUnits.h"
#include "gameProcessor/Units/humancolonists.h"
#include "enums/gameProcessingSettings.h"
#include "gameProcessor/playercontroller.h"
#endif

using namespace std;

/*************************************
FUNC: ColonyCenter(Sector *sec, int playerID)
DESC: Constructor
*************************************/
ColonyCenter::ColonyCenter(Sector *sec, int playerID):
    Settlement(sec, playerID),
    m_transportInHangar(0),
    m_transportControlled(0),
    m_prodProgress(0)
{
    m_type = t_HumanColonyCenter;
    m_fcontroller->setNewTexture(TextureProvider::getInstance()->getTexture(m_type));

    m_level = HUMAN_MAX_SETTLEMENT_LEVEL;
    m_populationLimit = HUM_POP_LIM_1;
}

/*************************************
FUNC: process()
DESC: Main proc func
*************************************/
void ColonyCenter::process()
{
    Settlement::process();

    if (m_transportControlled < HUM_COLONY_CENTER_TRANSPORT_HANGAR)
    {
        m_prodProgress += HUM_COLONY_CENTER_PRODUCTION;
        if (m_prodProgress >= HUM_SHUTL_TRANSPORT_COST)
        {
            m_transportControlled++;
            m_transportInHangar++;
            m_prodProgress = 0;
        }
    }

    if(m_transportInHangar > 0)
    {
        TryStartHumanColonistShutl();
    }
}

void ColonyCenter::checkState()
{
    //stub - do nothing
}

void ColonyCenter::TryStartHumanColonistShutl()
{
	MailController* mailContr = MailController::getInstance();
	Message* shutleRecvest = new CreateUnitMessage(t_HumanShuttle, this);
	Message* responce = mailContr->sendMessage(shutleRecvest);

	if (responce != NULL)
	{
		m_transportInHangar--;
	}

	delete responce;

    /*GObject* tar = PlayerController::getInstance()->getPlayer(m_playerID)->getEmigrantsTarget(m_x, m_y);
    if(tar != NULL)
    {
        cout << "Send shutl to " << tar->getX() << ":" << tar->getY() << endl;
        HumanColonists* Shuttle = new HumanColonists(this, tar, m_playerID);
        UnitController::getInstance()->addUnit(Shuttle);
        m_transportInHangar--;
    }*/
}

void ColonyCenter::returnToBase()
{
    m_transportInHangar++;
}

void ColonyCenter::lostShutle()
{
    m_transportControlled--;
}
