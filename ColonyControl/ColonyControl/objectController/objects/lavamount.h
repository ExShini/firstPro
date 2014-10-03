#ifndef LAVAMOUNT_H
#define LAVAMOUNT_H

#ifdef WIN32
#include "../../objectController/objects/sector.h"
#else
#include "objectController/objects/sector.h"
#endif



class LavaMount : public Sector
{
public:
    LavaMount();
};

#endif // LAVAMOUNT_H
