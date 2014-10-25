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
#define HUMAN_MAX_SETTLEMENT_LEVEL 9    //lower level = 0, top = 9, number of levels = 10
#define MIN_HUMAN_MOVE_DESIE 2

//next value means - how much infrastructure must be provided for achieve next settlement's level
#define HUM_INF_LVL_1 150
#define HUM_INF_LVL_2 1250 + HUM_INF_LVL_1
#define HUM_INF_LVL_3 7500 + HUM_INF_LVL_2
#define HUM_INF_LVL_4 26200 + HUM_INF_LVL_3
#define HUM_INF_LVL_5 135000 + HUM_INF_LVL_4
#define HUM_INF_LVL_6 135000 + HUM_INF_LVL_5
#define HUM_INF_LVL_7 135000 + HUM_INF_LVL_6
#define HUM_INF_LVL_8 135000 + HUM_INF_LVL_7
#define HUM_INF_LVL_9 135000 + HUM_INF_LVL_8

//next value means - how much people can live at current colony-settlement
#define HUM_POP_LIM_0 1000
#define HUM_POP_LIM_1 2000
#define HUM_POP_LIM_2 4000
#define HUM_POP_LIM_3 7000
#define HUM_POP_LIM_4 12000
#define HUM_POP_LIM_5 20000
#define HUM_POP_LIM_6 30000
#define HUM_POP_LIM_7 42000
#define HUM_POP_LIM_8 60000
#define HUM_POP_LIM_9 100000


//human's group is 16 people
#define HUMANS_GROPS(population) ( population >> 4 )
#define HUMAN_FOOD_PRODUCING 19

//each people eats 1 food point
#define HUMAN_FOOD_CONSUMPTIONS(population) (population)
#define HUMAN_HUNGER_DEMAGE(food) (food >> 2)   //25% will die

//population growth for human = 6.25%
#define HUMAN_POPULATION_GROWTH(population) (population >> 4)


#define HUMAN_POPULATION_BASE_LIMIT 8000
#define HUMAN_POPULATION_DEMAGE(food) (food >> 2)   //25% will die

#endif // GAMEPROCESSINGSETTINGS_H
