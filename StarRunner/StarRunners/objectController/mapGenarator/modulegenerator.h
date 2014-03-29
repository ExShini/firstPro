#ifndef MODULEGENERATOR_H
#define MODULEGENERATOR_H
#include "list"

#include "room.h"
#include "randomgen.h"

using namespace std;

class moduleGenerator
{
public:
    moduleGenerator();
    ~moduleGenerator();
    void generateModule(ModuleType moduleType);

protected:
    list<room *> *getRooms(ModuleType moduleType);
    bool checkArea(int x, int y,
                   int width, int height,
                   genMapField* map[GENERATED_MAP_WIDTH][GENERATED_MAP_HEIGHT]);

    RandomGen* m_randGen;
};

#endif // MODULEGENERATOR_H
