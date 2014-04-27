#ifndef MEDBOX_H
#define MEDBOX_H
#include "objectController/movableobj.h"

class MedBox : public ImmovableObj
{
public:
    MedBox(Direction dir);
};

#endif // MEDBOX_H
