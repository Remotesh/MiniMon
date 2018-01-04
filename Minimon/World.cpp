#include "World.h"

World::World(sf::RenderWindow& window, CommandQueue& commands)
	:mWindow(window)
	,mCommands(commands)
	, mWorldView(window.getDefaultView())
	, mWorldBounds(
		0.f,
		0.f,
		mWorldView.getSize().x,
		2000.f)
	, mSpawnPosition(
		mWorldView.getSize().x / 2.f,
		mWorldBounds.height - mWorldView.getSize().y),
	tileSize(64),
	mCurrentDungeon()
{
	loadTextures();

	// Remove Later
	test();

	//mWorldView.setCenter(mSpawnPosition);
}

void World::loadTextures()
{
	mTextures.load(Textures::Grid, "./media/textures/grid.png");
	mTextures.load(Textures::PlayerCharacter, "./media/textures/goodguy.png");
	mTextures.load(Textures::Enemy, "./media/textures/badguy.png");
	mTextures.load(Textures::Tiles, "./media/textures/tiles.png");
}

void World::test()
{
	
	playerSprite.setTexture(mTextures.get(Textures::PlayerCharacter));
	activeObjects.insert(std::make_pair(0, (*createPlayer())));
	activeObjects.at(0).setCoords(3, 3);

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
	playerSprite.setPosition(activeObjects.at(0).xCoord * 64, activeObjects.at(0).yCoord * 64);
	mWindow.draw(playerSprite);
}

void World::update(sf::Time dt)
{
	int cSize = mCommands.getSize();
	for (int i = 0; i < cSize; i++)
	{
		Command command = mCommands.pop();
		
		
		if (activeObjects.find(command.getId()) != activeObjects.end())
		{
			activeObjects.at(command.getId()).update(*this, command.getCommand());
		}
		else
		{
			if (inactiveObjects.find(command.getId()) != inactiveObjects.end())
			{

			}
		}
		
	}
}

void World::resolveCollision()
{

}