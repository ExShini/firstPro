#ifndef GAMEPROCESSINGSETTINGS_H
#define GAMEPROCESSINGSETTINGS_H

#define RAD1 57.29
#define UNIT_PROC_RATE 16
#define DEFAULT_PROC_TIME_POINT 1   //1 ms time point


//human's group is 16 people
#define HUMANS_GROPS(population) ( population >> 4 )
#define HUMAN_FOOD_PRODUCING 19

//each people eats 1 food point
#define HUMAN_FOOD_CONSUMPTIONS(population) (population)
#define HUMAN_HUNGER_DEMAGE(food) (food >> 2)   //25% will die

//population growth for human = 6.25%
#define HUMAN_POPULATION_GROWTH(population) (population >> 4)

//new human colonist equals 3.125% of population
#define HUMAN_COLONIST(population) (population >> 5)
#define HUMAN_RATE_OF_MOVING 2

#define HUMAN_POPULATION_BASE_LIMIT 8000
#define HUMAN_POPULATION_DEMAGE(food) (food >> 2)   //25% will die

#endif // GAMEPROCESSINGSETTINGS_H
