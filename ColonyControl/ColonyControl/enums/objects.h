#ifndef OBJECTS_H
#define OBJECTS_H

enum Direction
{
    NODIR = 0,
    UP,
    DOWN,
    LEFT,
    RIGHT
};

enum ObjectsType
{
    t_BACKGROUND,
    t_Floor,
    t_StationBlock,
    t_Wall,
    t_ArmoredWall,
    t_Door,
    t_TestObject1,
    t_TestObject2,
    t_MedBox,
    t_SF,
    NumberOfObjectTypes,
    NULLOBJECT
};


enum ModuleObjLevel
{
    MLEVEL_0 = 0,
    MLEVEL_1,
    MLEVEL_2,
    NUM_LEVELS
};

//MAP field settings
#define MAP_WIDTH 128  //WARNING! PART_OF_MAP_W and MAP_WIDTH should be synchronized!
#define MAP_HEIGHT 128  //WARNING! PART_OF_MAP_ and MAP_HEIGHT should be synchronized!

#define PART_OF_MAP_W >> 7  //WARNING! PART_OF_MAP_W and MAP_WIDTH should be synchronized!
#define PART_OF_MAP_H >> 7  //WARNING! PART_OF_MAP_ and MAP_HEIGHT should be synchronized!

#define M_ACCURACY_FACTOR << 7
#define D_ACCURACY_FACTOR >> 7

#endif // OBJECTS_H
