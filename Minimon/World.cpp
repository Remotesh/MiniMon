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

// Remove this later, this is just for testing.
void World::test()
{
	// Player
	std::cout << "First ID Create Start\n";
	createGObject(Textures::ID::PlayerCharacter, 0, 1, 3, 3, 10);
	std::cout << "First ID Create Finish\n";

	// Test Objects
	std::cout << "Second ID Create Start\n";
	createGObject(Textures::ID::PlayerCharacter, 1, 1, 3, 4, 7);
	std::cout << "Second ID Create Finish\n";
	createGObject(Textures::ID::PlayerCharacter, 2, 1, 5, 4, 2);
	std::cout << "Third ID Create Finish\n";
	createGObject(Textures::ID::Enemy, 3, 1, 6, 6, -1);
	std::cout << "Fourth ID Create Finish\n";
	createGObject(Textures::ID::Enemy, 4, 1, 1, 1, 0);
	std::cout << "Fifth ID Create Finish\n";

	std::cout << "Done Creating Test Objects\n";

	mCurrentDungeon.generateAddLevel(30, 30, Dungeons::WOODLANDS, Dungeons::RANDOM);
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

	std::cout << "Done with adding tests\n";
}

void World::createGObject(int textureID, int objectId, int objectType, int x = 0, int y = 0, int w = -1)
{
	commandComponents.emplace_back(ActiveCommandComponent());
	physicsComponents.emplace_back(ActivePhysicsComponent());
	graphicsComponents.emplace_back(ActiveGraphicsComponent(&(mTextures.get((Textures::ID)textureID))));

	GameObject newPlayer(&(commandComponents.back()), &(physicsComponents.back()), &(graphicsComponents.back()), objectId, x, y, w);

	addObject(&newPlayer, objectType);

	std::vector<GameObject>::iterator activeIt;
	for (activeIt = activeObjects.begin(); activeIt != activeObjects.end(); activeIt++)
	{
		std::cout << "0";
		sf::Sprite charSprite = *(activeIt->draw());
		std::cout << "0\n";
	}
};


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

	std::vector<GameObject>::iterator activeIt;
	for (activeIt = activeObjects.begin(); activeIt != activeObjects.end(); activeIt++)
	{
		sf::Sprite charSprite = *(activeIt->draw());
		charSprite.setPosition(activeIt->xCoord * 64, activeIt->yCoord * 64);
		mWindow.draw(charSprite);
	}

}

void World::update(sf::Time dt)
{
	mOss.str("");

	// Process Comamnds first
	int cSize = mCommands.getSize();
	if (cSize != 0)
	{
		for (int i = 0; i < cSize; i++)
		{
			Command command = mCommands.pop();
			std::vector<GameObject>::iterator it;
			int found = 0;

			for (it = activeObjects.begin(); it != activeObjects.end(); it++)
			{
				if (it->objectId == command.getId())
				{
					activeObjects.at(command.getId()).update(*this, command.getCommand(), dt);
					found = 1;
					break;
				}
			}

			if (found != 1)
			{
				for (it = inactiveObjects.begin(); it != inactiveObjects.end(); it++)
				{
					if (it->objectId == command.getId())
					{
						inactiveObjects.at(command.getId()).update(*this, command.getCommand(), dt);
						break;
					}
				}
			}
		}
	}

	std::vector<GameObject>::iterator it;
	for (it = activeObjects.begin(); it != activeObjects.end(); it++)
	{
		it->update(*this, 0, dt);
	}

	for (it = inactiveObjects.begin(); it != inactiveObjects.end(); it++)
	{
		it->update(*this, 0, dt);
	}
	
}

void World::addObject(GameObject* object, int type)
{

	if (type == 0)
	{
		inactiveObjects.push_back(*object);
	}
	else if (type == 1)
	{
		activeObjects.push_back(*object);
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

// For Testing Remove Later
DungeonLevel * World::getDungeonLevel()
{
	return &mCurrentDungeon.getDungeonLevel();
}

GameObject* World::checkCoord(int x, int y)
{
	GameObject* atPosition = nullptr;

	std::vector<GameObject>::iterator it;
	for (it = activeObjects.begin(); it != activeObjects.end(); it++)
	{
		if ((*it).xCoord == x && (*it).yCoord == y)
		{
			atPosition = &*it;
			break;
		}
	}
	return atPosition;
}

std::vector<GameObject*> World::collisionLine(int x, int y, int command)
{
	int curx = x;
	int cury = y;
	GameObject*					curlineObject = NULL;
	std::vector<GameObject*>	affectedObjects;

	// Cast a line out in the proper direction to grab all the affected objects
	switch (command)
	{
	case 1:
		cury--;
		while (cury >= 0)
		{
			curlineObject = checkCoord(curx, cury);
			if (curlineObject == nullptr)
				break;
			else
			{
				affectedObjects.push_back(curlineObject);
			}
			cury--;
		}
		break;
	case 2:
		curx--;
		while (curx >= 0)
		{
			curlineObject = checkCoord(curx, cury);
			if (curlineObject == nullptr)
				break;
			else
			{
				affectedObjects.push_back(curlineObject);
			}
			curx--;
		}
		break;
	case 3:
		cury++;
		while (cury < mCurrentArea->getHeight())
		{
			curlineObject = checkCoord(curx, cury);
			if (curlineObject == nullptr)
				break;
			else
			{
				affectedObjects.push_back(curlineObject);
			}
			cury++;
		}
		break;
	case 4:
		curx++;
		while (curx < mCurrentArea->getWidth())
		{
			curlineObject = checkCoord(curx, cury);
			if (curlineObject == nullptr)
				break;
			else
			{
				affectedObjects.push_back(curlineObject);
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
		std::vector<GameObject>::iterator otherObjectIt;
		for (otherObjectIt = activeObjects.begin(); otherObjectIt != activeObjects.end(); otherObjectIt++)
		{
			// Check passed in object's coords against every other object but otherObjectItself
			if (object != &*otherObjectIt)
			{
				if (object->xCoord == otherObjectIt->xCoord && object->yCoord == otherObjectIt->yCoord)
				{
					/*
					Weight Meaning / Caveats
					-1	- Unmoveable Walls and they should never have a non 0 status
					0	- Low weight items on the ground
					1	- Small enough to co-exist
					*/
					// If otherObjectIt is a wall move back the calling object as its immovable.
					if (otherObjectIt->weight == -1)
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

					// If the weight of the pushing object is greater than this otherObjectIt see what we can do
					if (otherObjectIt->weight > 1 && (object->weight > otherObjectIt->weight))
					{
						// Take this otherObjectIt and see if it were to move what other objects might it need to move
						std::vector<GameObject*> affectedObjects = collisionLine(object->xCoord, object->yCoord, object->status);
						std::vector<GameObject*>::iterator affectedObjectsIt;
						if (affectedObjects.size() > 0)
						{
							// Get total weight of all affected objects / see if any walls
							int totalWeight = otherObjectIt->weight;
							bool noWall = true;

							for (affectedObjectsIt = affectedObjects.begin(); affectedObjectsIt != affectedObjects.end(); affectedObjectsIt++)
							{
								if (*affectedObjectsIt != nullptr)
								{
									if ((*affectedObjectsIt)->weight == -1)
									{
										noWall = false;
										break;
									}
									totalWeight += (*affectedObjectsIt)->weight;
								}
							}

							if (noWall && (object->weight > totalWeight))
							{
								for (affectedObjectsIt = affectedObjects.begin(); affectedObjectsIt != affectedObjects.end(); affectedObjectsIt++)
								{
									if ((*affectedObjectsIt) != nullptr)
									{
										if ((*affectedObjectsIt)->weight > 1)
											(*affectedObjectsIt)->update(*this, object->status);
									}
								}
								otherObjectIt->update(*this, object->status);
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
							if(object->weight > otherObjectIt->weight)
								otherObjectIt->update(*this, object->status);
						}
					}
					else if (object->weight < otherObjectIt->weight)
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

					mOss << "Weight " << (object->weight) << " Status " << (object->status) << " Collided " << "Weight " << (otherObjectIt->weight) << " Status " << (otherObjectIt->status) << "\n";

				}
			}
		}
	}
}