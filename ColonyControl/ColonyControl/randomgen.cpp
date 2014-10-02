#include "randomgen.h"
#include <time.h>
#include <stdlib.h>
#include "enums/random_enums.h"

static short * randomTable = NULL;
static short randomConter = 0;

RandomGen::RandomGen()
{
    init();
}

void RandomGen::init()
{
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );

    short shift = now->tm_year + now->tm_mon + now->tm_mday + now->tm_hour + now->tm_min + now->tm_sec;

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
