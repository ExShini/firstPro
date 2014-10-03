#ifndef MODULEGENERATORSATTINGS_H
#define MODULEGENERATORSATTINGS_H

#define GENERATED_MAP_WIDTH 128
#define GENERATED_MAP_HEIGHT 128

//Mounts section
#define LAVA_PLANET_NUMBER_OF_MOUNT 450
#define LAVA_PLANET_MOUNT_LINGHT 7

//Lakes section
#define LAVA_PLANET_NUMBER_OF_LAVA_LAKES 200
#define LAVA_PLANET_LAVA_LAKES_LINGHT 4

//Fertility section
#define LAVA_PLANET_DEFAULT_MAX_OF_FERTILITY 1500
#define LAVA_PLANET_DEFAULT_MIN_OF_FERTILITY 500
#define LAVA_PLANET_NUMBER_OF_FERTILITY_FIELDS 80
#define LAVA_PLANET_POWER_OF_FERTILITY_FIELDS 400
#define LAVA_PLANET_TIME_OF_FERTILITY_FIELDS 8


//Mineral section
#define LAVA_PLANET_DEFAULT_MAX_OF_MINERAL 55
#define LAVA_PLANET_DEFAULT_MIN_OF_MINERAL 5
#define LAVA_PLANET_NUMBER_OF_MINERAL_FIELDS 60
#define LAVA_PLANET_POWER_OF_MINERAL_FIELDS 600
#define LAVA_PLANET_TIME_OF_MINERAL_FIELDS 2
#define LAVA_PLANET_LEGHT_OF_MINERAL_FIELDS 4

enum PlanetType
{
    LavaPlanet,
    NoType
};


#endif // MODULEGENERATORSATTINGS_H
