#ifndef LAVA_H
#define LAVA_H

#ifdef WIN32
#include "../../objectController/objects/sector.h"
#else
#include "objectController/objects/sector.h"
#endif



class Lava: public Sector
{
public:
    Lava();
};

#endif // LAVA_H
