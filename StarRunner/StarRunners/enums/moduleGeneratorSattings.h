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

#define CostFloor 1
#define CostWall 20

#endif // MODULEGENERATORSATTINGS_H
