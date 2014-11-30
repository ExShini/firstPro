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
    t_TargetObject,
    t_Sector,
    t_LavaMount,
    t_Lava,

    //human objects
    t_HumanSettlers,
    t_HumanColonyCenter,
    t_HumanFighter,


    //UI Elements
    t_HumanInfoBar,
    t_singleTextController,

    NumberOfObjectTypes,
    NULLOBJECT
};

enum UIElementType
{
    e_fertitilyUIC,
    e_mineralWealthUIC,

    e_populationUIC,
    e_foodStorageUIC,
    e_mineralStoargeUIC,


    e_settlementLevelUIC,
    e_infrostructureUIC
};

enum ModuleObjLevel
{
    SECTOR_LEVEL = 0,
    SETTLEMENT_LEVEL,
    MLEVEL_2,
    NUM_LEVELS
};

//MAP field settings
#define MAP_WIDTH 64  //WARNING! PART_OF_MAP_W and MAP_WIDTH should be synchronized!
#define MAP_HEIGHT 64  //WARNING! PART_OF_MAP_ and MAP_HEIGHT should be synchronized!

#define PART_OF_MAP_W >> 6  //WARNING! PART_OF_MAP_W and MAP_WIDTH should be synchronized!
#define PART_OF_MAP_H >> 6  //WARNING! PART_OF_MAP_ and MAP_HEIGHT should be synchronized!

#define M_ACCURACY_FACTOR << 7
#define D_ACCURACY_FACTOR >> 7

#endif // OBJECTS_H
