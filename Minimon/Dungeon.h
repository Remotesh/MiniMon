#pragma once

#include "DungeonLevel.h"
#include "vector"

class Dungeon
{
public:
	Dungeon();
	Dungeon(Dungeons::Difficulty);
	void addLevel(DungeonLevel);
	void generateAddLevel();
	void generateAddLevel(int, int, Dungeons::Type, Dungeons::SubType);
	void setDifficulty(Dungeons::Difficulty);

	DungeonLevel& getDungeonLevel(int);

	Dungeons::Difficulty getDifficulty();

private:
	std::vector<DungeonLevel> dungeonLayout;
	int numFloors = 0;
	Dungeons::Difficulty dungeonDifficulty;
};