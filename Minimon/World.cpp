#include "World.h"
#include "HelperFuncs.h"

World::World(sf::RenderWindow& window, CommandQueue& commands)
	:mWindow(window)
	,mCommands(commands)
	, mWorldView(window.getDefaultView())
	, mWorldBounds(
		0.f,
		0.f,
		mWorldView.getSize().x,
		2000.f)
	, tileSize(64)
	, mCurrentDungeon()
{
	loadTextures();

	// Remove Later
	test();
}

void World::loadTextures()
{
	mTextures.load(Textures::Grid, "./media/textures/grid.png");
	mTextures.load(Textures::PlayerCharacter, "./media/textures/smileysheet.png");
	mTextures.load(Textures::Enemy, "./media/textures/squareysheet.png");
	mTextures.load(Textures::Tiles, "./media/textures/tiles.png");
}

void World::test()
{
	addObject((*createPlayer(&(mTextures.get(Textures::PlayerCharacter)))), 0, 1);
	activeObjects.at(0).setCoords(3, 3);
	activeObjects.at(0).weight = 10;

	addObject((*createPlayer(&(mTextures.get(Textures::PlayerCharacter)))), 1, 1);
	activeObjects.at(1).setCoords(3, 4);
	activeObjects.at(1).weight = 7;

	addObject((*createPlayer(&(mTextures.get(Textures::PlayerCharacter)))), 2, 1);
	activeObjects.at(2).setCoords(5, 4);
	activeObjects.at(2).weight = 2;

	addObject((*createPlayer(&(mTextures.get(Textures::Enemy)))), 3, 1);
	activeObjects.at(3).setCoords(6, 6);
	activeObjects.at(3).weight = -1;

	addObject((*createPlayer(&(mTextures.get(Textures::Enemy)))), 4, 1);
	activeObjects.at(4).setCoords(1, 1);
	activeObjects.at(4).weight = 0;

	mCurrentDungeon.generateAddLevel(20, 20, Dungeons::Woodlands, Dungeons::Square);
	mCurrentArea = (Area *) &(mCurrentDungeon.getDungeonLevel(0));

	grid.setTexture(mTextures.get(Textures::Grid));

	for (int i = 0; i < 10; i++)
		woodlands[i].setTexture(mTextures.get(Textures::Tiles));

	woodlands[0].setTextureRect(sf::IntRect(0 + 256, 0, tileSize, tileSize));
	woodlands[1].setTextureRect(sf::IntRect(63 + 256, 0, tileSize, tileSize));
	woodlands[2].setTextureRect(sf::IntRect(127 + 256, 0, tileSize, tileSize));
	woodlands[3].setTextureRect(sf::IntRect(0 + 256, 63, tileSize, tileSize));
	woodlands[4].setTextureRect(sf::IntRect(63 + 256, 63, tileSize, tileSize)); // Base Tile
	woodlands[5].setTextureRect(sf::IntRect(127 + 256, 63, tileSize, tileSize));
	woodlands[6].setTextureRect(sf::IntRect(0 + 256, 127, tileSize, tileSize));
	woodlands[7].setTextureRect(sf::IntRect(63 + 256, 127, tileSize, tileSize));
	woodlands[8].setTextureRect(sf::IntRect(127 + 256, 127, tileSize, tileSize));
	woodlands[9].setTextureRect(sf::IntRect(191 + 256, 191, tileSize, tileSize)); // Base Wall
}


void World::draw()
{
	// Worldview To be centered on player
	mWorldView.setCenter(sf::Vector2f(64 * activeObjects.at(0).xCoord, 64 * activeObjects.at(0).yCoord));
	mWindow.setView(mWorldView);
	//Apply the grid to view
	for (int i = 0; i < mCurrentArea->getWidth(); i++)
	{
		int x = i;
		for (int j = 0; j < mCurrentArea->getHeight(); j++)
		{
			int y = j;
			if (mCurrentArea->getLayout()[i][j] != -1)
			{
				switch (mCurrentArea->getLayout()[i][j]) {
				case 0:
					woodlands[4].setPosition(x * 64, y * 64);
					mWindow.draw(woodlands[4]);
					break;
				case 15:
					woodlands[9].setPosition(x * 64, y * 64);
					mWindow.draw(woodlands[9]);
					break;

				case 14:
					woodlands[2].setPosition(x * 64, y * 64);
					mWindow.draw(woodlands[2]);
					break;
				case 13:
					woodlands[1].setPosition(x * 64, y * 64);
					mWindow.draw(woodlands[1]);
					break;
				case 12:
					woodlands[0].setPosition(x * 64, y * 64);
					mWindow.draw(woodlands[0]);
					break;
				case 11:
					woodlands[3].setPosition(x * 64, y * 64);
					mWindow.draw(woodlands[3]);
					break;
				case 10:
					woodlands[6].setPosition(x * 64, y * 64);
					mWindow.draw(woodlands[6]);
					break;
				case 9:
					woodlands[7].setPosition(x * 64, y * 64);
					mWindow.draw(woodlands[7]);
					break;
				case 8:
					woodlands[8].setPosition(x * 64, y * 64);
					mWindow.draw(woodlands[8]);
					break;
				case 7:
					woodlands[5].setPosition(x * 64, y * 64);
					mWindow.draw(woodlands[5]);
					break;
				}
			}
			grid.setPosition(x * 64, y * 64);
			mWindow.draw(grid);
		}
	}

	// move PlayerTexture around where it needs to be

	for (int i = 0; i < activeObjects.size(); i++)
	{
		sf::Sprite charSprite = (activeObjects.at(i).draw());
		charSprite.setPosition(activeObjects.at(i).xCoord * 64, activeObjects.at(i).yCoord * 64);
		mWindow.draw(charSprite);
	}

}

void World::update(sf::Time dt)
{
	mOss.str("");
	int cSize = mCommands.getSize();
	if (cSize != 0)
	{
		for (int i = 0; i < cSize; i++)
		{
			Command command = mCommands.pop();

			if (activeObjects.find(command.getId()) != activeObjects.end())
			{
				activeObjects.at(command.getId()).update(*this, command.getCommand(), dt);
			}
			else
			{
				if (inactiveObjects.find(command.getId()) != inactiveObjects.end())
				{
					inactiveObjects.at(command.getId()).update(*this, command.getCommand(), dt);
				}
			}
		}
	}
	else
	{
		std::map<const int, GameObject>	::iterator it;
		for (it = activeObjects.begin(); it != activeObjects.end(); it++)
		{
			it->second.update(*this, 0, dt);
		}
		
		for (it = inactiveObjects.begin(); it != inactiveObjects.end(); it++)
		{
			it->second.update(*this, 0, dt);
		}

	}
	
}

void World::addObject(GameObject object, int id, int type)
{

	if (type == 0)
	{
		inactiveObjects.insert(std::make_pair(id, object));
	}
	else if (type == 1)
	{
		activeObjects.insert(std::make_pair(id, object));
		GObjectPointer* newList = new GObjectPointer[activeObjects.size()];

		std::map<const int, GameObject>	::iterator it;
		int i = 0;
		for (it = activeObjects.begin(); it != activeObjects.end(); it++)
		{
			GObjectPointer newPointer;
			newPointer.object = &it->second;
			newPointer.xCoord = &newPointer.object->xCoord;
			newPointer.yCoord = &newPointer.object->yCoord;
			newList[i] = newPointer;
			i++;
		}
		activeCoords = newList;
	}
}

std::string World::getDebug()
{
	return mOss.str();
}

Area* World::getArea()
{
	return mCurrentArea;
}

GObjectPointer* World::checkCoord(int x, int y)
{
	GObjectPointer atPosition;
	atPosition.object = nullptr;
	for (int i = 0; i < activeObjects.size(); i++)
	{
		if ((*(activeCoords[i].xCoord) == x) && (*(activeCoords[i].yCoord) == y))
		{
			atPosition = (activeCoords[i]);
			break;
		}
	}
	return &atPosition;
}

GObjectPointerArray World::collisionLine(int x, int y, int command)
{
	int curx = x;
	int cury = y;
	int numAffectedObjects = 0;
	GObjectPointer*				curlineObject = NULL;
	GObjectPointerArray			affectedObjects;

	// Cast a line out in the proper direction to grab all the affected objects
	switch (command)
	{
	case 1:
		cury--;
		while (cury >= 0)
		{
			curlineObject = checkCoord(curx, cury);
			if (curlineObject->object == nullptr)
				break;
			else
			{
				affectedObjects.add(*curlineObject);
			}
			cury--;
		}
		break;
	case 2:
		curx--;
		while (curx >= 0)
		{
			curlineObject = checkCoord(curx, cury);
			if (curlineObject->object == nullptr)
				break;
			else
			{
				affectedObjects.add(*curlineObject);
			}
			curx--;
		}
		break;
	case 3:
		cury++;
		while (cury < mCurrentArea->getHeight())
		{
			curlineObject = checkCoord(curx, cury);
			if (curlineObject->object == nullptr)
				break;
			else
			{
				affectedObjects.add(*curlineObject);
			}
			cury++;
		}
		break;
	case 4:
		curx++;
		while (curx < mCurrentArea->getWidth())
		{
			curlineObject = checkCoord(curx, cury);
			if (curlineObject->object == nullptr)
				break;
			else
			{
				affectedObjects.add(*curlineObject);
			}
			curx++;
		}
		break;
	}

	return affectedObjects;
}

void World::resolveCollision(GameObject* object)
{
	/* Commands for Movement
	1 - Up
	2 - Left
	3 - Down
	4 - Right
	*/

	if (object->weight != -1 || object->weight != 0 || object->weight != 1)
	{
		std::map<const int, GameObject>	::iterator it;
		for (it = activeObjects.begin(); it != activeObjects.end(); it++)
		{

			if (object != &(it->second))
			{
				if (object->xCoord == it->second.xCoord && object->yCoord == it->second.yCoord)
				{
					/*
					Weight Meaning / Caveats
					-1	- Unmoveable Walls and they should never have a non 0 status
					0	- Low weight items on the ground
					1	- Small enough to co-exist
					*/
					if (it->second.weight == -1)
					{
						switch (object->status)
						{
						case 1:
							object->update(*this, 3);
							break;
						case 2:
							object->update(*this, 4);
							break;
						case 3:
							object->update(*this, 1);
							break;
						case 4:
							object->update(*this, 2);
							break;
						}
					}

					if (it->second.weight > 1 && (object->weight > it->second.weight))
					{
						GObjectPointerArray allObjects = collisionLine(object->xCoord, object->yCoord, object->status);
						if (allObjects.size != 0)
						{
							// Get total weight of all affected objects / see if any walls
							int totalWeight = it->second.weight;
							bool noWall = true;

							for (int i = 0; i < allObjects.size; i++)
							{
								if (allObjects.gOPArray[i].object != nullptr)
								{
									if (allObjects.gOPArray[i].object->weight == -1)
									{
										noWall = false;
										break;
									}
									totalWeight += allObjects.gOPArray[i].object->weight;
								}
							}

							if (noWall && (object->weight > totalWeight))
							{
								for (int i = 0; i < allObjects.size; i++)
								{
									if (allObjects.gOPArray[i].object != nullptr)
									{
										if (allObjects.gOPArray[i].object->weight > 1)
											allObjects.gOPArray[i].object->update(*this, object->status);
									}
								}
								it->second.update(*this, object->status);
							}
							else
							{
								// Reverse Object
								switch (object->status)
								{
								case 1:
									object->update(*this, 3);
									break;
								case 2:
									object->update(*this, 4);
									break;
								case 3:
									object->update(*this, 1);
									break;
								case 4:
									object->update(*this, 2);
									break;
								}
							}
						}
						else
						{
							if(object->weight > it->second.weight)
								it->second.update(*this, object->status);
						}
					}
					else if (object->weight < it->second.weight)
					{
						// Reverse Object
						switch (object->status)
						{
						case 1:
							object->update(*this, 3);
							break;
						case 2:
							object->update(*this, 4);
							break;
						case 3:
							object->update(*this, 1);
							break;
						case 4:
							object->update(*this, 2);
							break;
						}
					}

					mOss << "Weight " << (object->weight) << " Status " << (object->status) << " Collided " << "Weight " << (it->second.weight) << " Status " << (it->second.status) << "\n";

				}
			}
		}
	}
}