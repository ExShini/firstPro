#ifndef UNITCONTROLLER_H
#define UNITCONTROLLER_H
#include "vector"
#include "unit.h"

using namespace std;

class UnitController
{
public:
    static UnitController* getInstance();
    void init();
    void process();
    void addUnit(Unit*unit);

protected:
    static UnitController* m_instance;
    UnitController();
    vector<Unit*>* m_units;
};

#endif // UNITCONTROLLER_H
