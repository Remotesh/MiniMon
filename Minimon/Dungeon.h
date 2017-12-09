#pragma once

#include "map"

class DungeonLevel;

namespace Dungeons
{
	enum Type {
		Woodlands,
		Desert,
		Cave
	};

	enum SubType {
		Small,
		Medium,
		Large,
		Square
	};

	enum Difficulty {
		Easy,
		Normal,
		Hard,
		Expert
	};
}

class Dungeon
{
public:
	Dungeon(Dungeons::Difficulty);
	void addLevel(DungeonLevel);
	void generateAddLevel();
	void setDifficulty(Dungeons::Difficulty);

	Dungeons::Difficulty getDifficulty();

private:
	std::map<int, DungeonLevel> dungeonLayout;
	int numFloors = 0;
	Dungeons::Difficulty dungeonDifficulty;
};