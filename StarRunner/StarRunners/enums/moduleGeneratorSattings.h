#ifndef MODULEGENERATORSATTINGS_H
#define MODULEGENERATORSATTINGS_H

#define GENERATED_MAP_WIDTH 100
#define GENERATED_MAP_HEIGHT 100

enum Direction
{
    NODIR,
    UP,
    DOWN,
    LEFT,
    RIGHT
};

enum ModuleType
{
    ResidentialUnit,
    MedicalModule,
    EngineeringCompartment,
    EngineCompartment,
    NoType
};

enum ModuleGenLevel
{
    MLEVEL_0 = 0,
    MLEVEL_1,
    MLEVEL_2,
    NUM_LEVELS
};

#define roomBorder 2

#define CostFloor 1
#define CostWall 20
#define CostEmpty 5



#endif // MODULEGENERATORSATTINGS_H
