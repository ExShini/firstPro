#ifndef COLONYCENTER_H
#define COLONYCENTER_H
#include "settlement.h"

class ColonyCenter: public Settlement
{
public:
    ColonyCenter(Sector* sec, int playerID);
    void process();
    void returnToBase();
    void lostShutle();


protected:
    int m_transportInHangar;
    int m_transportControlled;
    int m_prodProgress;

    void TryStartHumanColonistShutl();
    void checkState();


};

#endif // COLONYCENTER_H
