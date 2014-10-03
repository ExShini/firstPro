#ifndef PLANETMAP_H
#define PLANETMAP_H
#include "map"

#ifdef WIN32
#include "../../objectController/gobject.h"
#else
#include "objectController/gobject.h"
#endif



class Layer
{
public:
	Layer()
	{
		for(int i = 0; i < MAP_WIDTH; i ++)
		{
			for(int j = 0; j < MAP_HEIGHT; j++)
			{
				lMap[i][j] = NULL;
			}
		}
	}
	
	GObject* lMap[MAP_WIDTH][MAP_HEIGHT];
};


class PlanetMap
{
public:
    PlanetMap();
    Layer* objects[NUM_LEVELS];
};

#endif // PLANETMAP_H
