#include "randomgen.h"
#include <time.h>
#include <stdlib.h>
#include "enums/random_enums.h"

#ifdef WIN32
#include"SDL.h"
#else
#include"SDL2/SDL.h"
#endif

static short * randomTable = NULL;
static short randomConter = 0;

RandomGen::RandomGen()
{
    init();
}

void RandomGen::init()
{

    time_t td;
    td = time(NULL);

    short shift = td % MAX_RAND_NUM;

    randomTable = (short*) (malloc(sizeof(short) * RAND_BUFF_LENGTH));
    if ( randomTable != NULL )
    {
        for (int i = 0; i < RAND_BUFF_LENGTH; i++)
        {
            randomTable[i] = (rand() + shift) % MAX_RAND_NUM;
        }
    }
}

short RandomGen::getRand()
{
    short ret;

    ret = randomTable[randomConter];
    randomConter++;
    if (randomConter >= RAND_BUFF_LENGTH)
    {
        randomConter = 0;
    }
    return ret;
}
