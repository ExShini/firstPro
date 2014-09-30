#ifndef OBJECTS_H
#define OBJECTS_H

enum Direction
{
    UP = 0,
    DOWN,
    LEFT,
    RIGHT,
    NUMBER_OF_DIRECTIONS = 4,
    NO_DIR
};

enum ObjectsType
{
    t_BACKGROUND,
    t_CameraObject,
    t_Sector,
    t_HumanSettlers,
    t_LavaMount,
    t_Lava,
    NumberOfObjectTypes,
    NULLOBJECT
};


enum ModuleObjLevel
{
    SECTOR_LEVEL = 0,
    SETTLEMENT_LEVEL,
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
