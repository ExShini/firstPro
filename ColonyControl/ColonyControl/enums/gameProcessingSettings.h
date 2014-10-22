#ifndef GAMEPROCESSINGSETTINGS_H
#define GAMEPROCESSINGSETTINGS_H

#define RAD1 57.29
#define UNIT_PROC_RATE 16
#define DEFAULT_PROC_TIME_POINT 1   //1 ms time point

#define NUMBER_OF_PLAYERS 8

enum Race
{
    Human = 0,
    Aroi,
    NoRace
};

//human settlement settings:

enum BuildingsLevels
{
    BUILD_LEVEL_0 = 0,
    BUILD_LEVEL_1,
    BUILD_LEVEL_2,
    BUILD_LEVEL_3,
    BUILD_LEVEL_4,
    BUILD_LEVEL_5,
    BUILD_LEVEL_6,
    BUILD_LEVEL_7,
    BUILD_LEVEL_8,
    BUILD_LEVEL_9,
    BUILD_LEVEL_10,
    BUILD_LEVEL_11,
    NUMBER_OF_LEVELS,
    HUMAN_MAX_LEVEL = BUILD_LEVEL_9
};

//human's group is 16 people
#define HUMANS_GROPS(population) ( population >> 4 )
#define HUMAN_FOOD_PRODUCING 19

//each people eats 1 food point
#define HUMAN_FOOD_CONSUMPTIONS(population) (population)
#define HUMAN_HUNGER_DEMAGE(food) (food >> 2)   //25% will die

//population growth for human = 3.125%
#define HUMAN_POPULATION_GROWTH(population) (population >> 5)


#define HUMAN_POPULATION_BASE_LIMIT 8000
#define HUMAN_POPULATION_DEMAGE(food) (food >> 2)   //25% will die

#endif // GAMEPROCESSINGSETTINGS_H
