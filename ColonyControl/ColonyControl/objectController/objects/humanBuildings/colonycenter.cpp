#include "colonycenter.h"

#ifdef WIN32
#include "../../../enums/Units/humanUnits.h"
#else
#include "enums/Units/humanUnits.h"
#endif

ColonyCenter::ColonyCenter(Sector *sec, int playerID):
    Settlement(sec, playerID),
    m_transportInHangar(0),
    m_transportControlled(0),
    m_prodProgress(0)
{
    m_type = t_HumanColonyCenter;
    m_fcontroller->setNewTexture(TextureProvider::getInstance()->getTexture(m_type));
}

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
        }
    }

    if(m_transportInHangar > 0)
    {
        TryFindTransportMission();
    }
}


void ColonyCenter::TryFindTransportMission()
{

}
