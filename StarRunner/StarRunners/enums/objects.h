#ifndef OBJECTS_H
#define OBJECTS_H

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
#define MAP_WIDTH 256  //WARNING! PART_OF_MAP_W and MAP_WIDTH should be synchronized!
#define MAP_HEIGHT 256  //WARNING! PART_OF_MAP_ and MAP_HEIGHT should be synchronized!

#define PART_OF_MAP_W >> 8  //WARNING! PART_OF_MAP_W and MAP_WIDTH should be synchronized!
#define PART_OF_MAP_H >> 8  //WARNING! PART_OF_MAP_ and MAP_HEIGHT should be synchronized!

#define M_ACCURACY_FACTOR << 8
#define D_ACCURACY_FACTOR >> 8

#endif // OBJECTS_H
