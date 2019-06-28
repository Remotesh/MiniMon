#pragma once
#include "Area.h"
#include "DungeonIdentifier.inl"
#include <random>
#include <time.h>  

class DungeonLevel : public Area
{
public:
	DungeonLevel();
	DungeonLevel(int, int, Dungeons::Type, Dungeons::SubType);

	void generateArea(int);
	void randomGen(int);

private:
	Dungeons::Type dungeonType;
	Dungeons::SubType dungeonSubType;
	int basetile, basewall, topright, topmid, topleft, leftmid, bottomleft, bottommid, bottomright, rightmid;
};