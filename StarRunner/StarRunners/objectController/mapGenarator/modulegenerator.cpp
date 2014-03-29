#include "modulegenerator.h"
#include "list"

using namespace std;

moduleGenerator::moduleGenerator()
{
}


void moduleGenerator::generateModule()
{
    list<genMapField*> ping, pong;
    list<genMapField*>* procList;

    genMapField* costMap[GENERATED_MAP_WIDTH][GENERATED_MAP_HEIGHT];

    for (int i = 0; i < GENERATED_MAP_WIDTH; i++)
    {
        for (int j = 0; j < GENERATED_MAP_HEIGHT; j++)
        {
            costMap[i][j] = new genMapField();
        }
    }


}
