#pragma once
#include "Area.h"
#include "Dungeon.h"

class DungeonLevel : public Area
{
public:
	DungeonLevel();
	DungeonLevel(int, int, Dungeons::Type, Dungeons::SubType);

	void generateArea();

private:
	Dungeons::Type dungeonType;
	Dungeons::SubType dungeonSubType;
};