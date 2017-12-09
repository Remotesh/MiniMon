#include "Dungeon.h"
#include "DungeonLevel.h"

Dungeon::Dungeon(Dungeons::Difficulty diff)
	:dungeonDifficulty(diff)
{
}

void Dungeon::addLevel(DungeonLevel level)
{
	numFloors++;
	dungeonLayout.insert(std::pair<int, DungeonLevel>(numFloors, level));
}

void Dungeon::generateAddLevel()
{
	DungeonLevel newLevel;
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