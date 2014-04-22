#ifndef MODULEGENERATOR_H
#define MODULEGENERATOR_H
#include "list"
#include "vector"

#include "room.h"
#include "randomgen.h"
#include "objectController/gobject.h"
#include "module.h"

using namespace std;

class moduleGenerator
{
public:
    moduleGenerator();
    ~moduleGenerator();
    Module *generateModule(ModuleType moduleType);

protected:
    vector<room *> *getRooms(ModuleType moduleType);
    bool checkArea(int x, int y, room *croom);
    void placeRoom(room *croom, int x, int y);

    void createCorridors(room *croom, room *troom);

    int getFieldKey(int x, int y);
    int getCostByType(ObjectsType type);
    GObject* getGObjectByType(ObjectsType type);

    RandomGen* m_randGen;

    genMapField* m_costMap[GENERATED_MAP_WIDTH][GENERATED_MAP_HEIGHT];
};

#endif // MODULEGENERATOR_H
