#ifndef SECTORRADAR_H
#define SECTORRADAR_H
#include "coordinate.h"

class SectorRadar
{
public:
    SectorRadar(int radius, int x, int y, int ScanLevel);
    Coordinate *area;
};


#endif // SECTORRADAR_H
