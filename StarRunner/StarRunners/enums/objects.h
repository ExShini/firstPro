#ifndef OBJECTS_H
#define OBJECTS_H

enum ObjectsType
{
    BACKGROUND,
    TestObject1,
    TestObject2,
    NumberOfTextures,
    NULLOBJECT
};

//MAP field settings
#define MAP_WIDTH 256  //WARNING! PART_OF_MAP_W and MAP_WIDTH should be synchronized!
#define MAP_HEIGHT 256  //WARNING! PART_OF_MAP_ and MAP_HEIGHT should be synchronized!

#define PART_OF_MAP_W >> 8  //WARNING! PART_OF_MAP_W and MAP_WIDTH should be synchronized!
#define PART_OF_MAP_H >> 8  //WARNING! PART_OF_MAP_ and MAP_HEIGHT should be synchronized!

#define M_ACCURACY_FACTOR << 8
#define D_ACCURACY_FACTOR >> 8

#endif // OBJECTS_H
