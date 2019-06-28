#include "Dungeon.h"

Dungeon::Dungeon()
	:dungeonDifficulty(Dungeons::Difficulty::EASY)
{}

Dungeon::Dungeon(Dungeons::Difficulty diff)
	:dungeonDifficulty(diff)
{
}

void Dungeon::addLevel(DungeonLevel level)
{
	dungeonLayout.push_back(level);
	numFloors++;
}

void Dungeon::generateAddLevel()
{
	DungeonLevel newLevel;
	addLevel(newLevel);
}

void Dungeon::generateAddLevel(int w, int h, Dungeons::Type leveltype, Dungeons::SubType levelsubtype)
{
	DungeonLevel newLevel = DungeonLevel(w, h, leveltype, levelsubtype);
	addLevel(newLevel);
}

void Dungeon::setDifficulty(Dungeons::Difficulty diff)
{
	dungeonDifficulty = diff;
}

Dungeons::Difficulty Dungeon::getDifficulty()
{
	return dungeonDifficulty;
}

DungeonLevel& Dungeon::getDungeonLevel()
{
	if (currFloor <= numFloors)
	{
		return dungeonLayout.at(currFloor);
	}
}

DungeonLevel& Dungeon::getDungeonLevel(int num)
{
	if (num <= numFloors)
	{
		currFloor = num;
		return dungeonLayout.at(num);
	}
}