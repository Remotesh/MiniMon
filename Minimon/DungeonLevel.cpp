#include "DungeonLevel.h"

DungeonLevel::DungeonLevel()
	: Area()
{
	generateArea();
}

DungeonLevel::DungeonLevel(int w, int h, Dungeons::Type dungtype, Dungeons::SubType dungsubtype)
	: Area(w,h),
	dungeonType(dungtype),
	dungeonSubType(dungsubtype)
{
	generateArea();
}

void DungeonLevel::generateArea()
{
	/*
	Dungeon Type Tileset Ranges
	Woodlands	: 0-15
	Desert		: 16-31
	Cave		: 32-47

	Dungeon Subtype
	Small
	Medium
	Large
	Square
	*/
	int basetile, basewall, topright, topmid, topleft, leftmid, bottomleft, bottommid, bottomright, rightmid;

	switch(dungeonType) {
	case Dungeons::Type::Woodlands:
		basetile	= 0;
		basewall	= 15;
		topright	= 14;
		topmid		= 13;
		topleft		= 12;
		leftmid		= 11;
		bottomleft	= 10;
		bottommid	= 9;
		bottomright	= 8;
		rightmid	= 7;
		break;
	case Dungeons::Type::Desert:
		basetile	= 16;
		basewall	= 31;
		topright	= 30;
		topmid		= 29;
		topleft		= 28;
		leftmid		= 27;
		bottomleft	= 26;
		bottommid	= 25;
		bottomright	= 24;
		rightmid	= 23;
		break;
	case Dungeons::Type::Cave:
		basetile	= 32;
		basewall	= 47;
		topright	= 46;
		topmid		= 45;
		topleft		= 44;
		leftmid		= 43;
		bottomleft	= 42;
		bottommid	= 41;
		bottomright	= 40;
		rightmid	= 39;
		break;
	default:
		basetile = 0;
		break;
	};

	layout = new int*[width];
	for (int i = 0; i < width; i++)
	{
		layout[i] = new int[height];
	}

	// Fill it with Nothing
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			layout[i][j] = basetile;
		}
	}

	if (dungeonSubType == Dungeons::SubType::Square)
	{
		// Ring off Full Walls
		for (int i = 0; i < width; i++)
		{
			layout[i][0] = basewall;
			layout[i][height - 1] = basewall;
		}
		for (int j = 0; j < height; j++)
		{
			layout[0][j] = basewall;
			layout[width - 1][j] = basewall;
		}
		// Top/Bot Middle
		for (int i = 2; i < width - 2; i++)
		{
			layout[i][1] = topmid;
			layout[i][height - 2] = bottommid;
		}
		//	Left/Right Middle
		for (int j = 2; j < height - 2; j++)
		{
			layout[1][j] = leftmid;
			layout[width - 2][j] = rightmid;
		}
		// TL TR BL BR
		layout[1][1] = topleft;
		layout[width - 2][1] = topright;
		layout[1][height - 2] = bottomleft;
		layout[width - 2][height - 2] = bottomright;
	}
}