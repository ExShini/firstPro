#ifndef MODULEGENERATOR_H
#define MODULEGENERATOR_H
#include "list"
#include "vector"

#include "room.h"
#include "randomgen.h"
#include "objectController/gobject.h"

using namespace std;

class moduleGenerator
{
public:
    moduleGenerator();
    ~moduleGenerator();
    list<GObject *> *generateModule(ModuleType moduleType);

protected:
    vector<room *> *getRooms(ModuleType moduleType);
    bool checkArea(int x, int y,
                   int width, int height,
                   genMapField* map[GENERATED_MAP_WIDTH][GENERATED_MAP_HEIGHT]);
    void placeRoom(room *croom, int x, int y, genMapField *genMap[GENERATED_MAP_WIDTH][GENERATED_MAP_HEIGHT],
                   list<GObject *> *objList);

    void createCorridors(room *croom, room *troom, genMapField *genMap[GENERATED_MAP_WIDTH][GENERATED_MAP_HEIGHT]);

    int getFieldKey(int x, int y);
    int getCostByType(ObjectsType type);
    GObject* getGObjectByType(ObjectsType type);

    RandomGen* m_randGen;
};

#endif // MODULEGENERATOR_H
