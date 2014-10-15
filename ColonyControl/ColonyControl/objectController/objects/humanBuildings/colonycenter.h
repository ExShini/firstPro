#ifndef COLONYCENTER_H
#define COLONYCENTER_H
#include "settlement.h"

class ColonyCenter: public Settlement
{
public:
    ColonyCenter(Sector* sec, int playerID);
    void process();


protected:
    int m_transportInHangar;
    int m_transportControlled;
    int m_prodProgress;
    int processingMap[][2];

    void TryFindTransportMission();

};

#endif // COLONYCENTER_H
