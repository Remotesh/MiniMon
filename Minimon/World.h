#pragma once

#include <map>
#include <string>
#include <sstream>

#include "SFML\Graphics.hpp"
#include "ResourceHolder.h"
#include "ResourceIdentifier.h"

#include "Area.h"
#include "Dungeon.h"
#include "CommandQueue.h"

#include "GameObject.h"
#include "Player.h"


#include <iostream>

class World : private sf::NonCopyable
{
public:
	explicit		World(sf::RenderWindow& window, CommandQueue& commands);
	void			update(sf::Time dt);
	void			draw();
	void			resolveCollision(GameObject*);
	Area*			getArea();
	DungeonLevel*	getDungeonLevel();
	std::string		getDebug();

private:
	void			loadTextures();

	GameObject*					checkCoord(int, int);
	std::vector<GameObject*>	collisionLine(int, int, int);

	void		addObject(GameObject *, int);

	void		test();

	void createGObject(int, int, int, int, int, int);

private:
	enum Layer {
		Tiles,
		Items,
		Objects,
		Grid,
		LayerCount
	};

private:
	sf::RenderWindow&					mWindow;
	sf::View							mWorldView;
	TextureHolder						mTextures;
	CommandQueue&						mCommands;
	Area*								mCurrentArea = NULL;
	Dungeon								mCurrentDungeon;

	//Removed Later
	sf::Sprite							grid;
	sf::Sprite*							woodlands = new sf::Sprite[10];
	sf::Clock							debugClock;

	std::ostringstream					mOss;

	std::vector<GameObject>				activeObjects;
	std::vector<GameObject>				inactiveObjects;
	
	std::vector<ActiveCommandComponent>		commandComponents;
	std::vector<ActivePhysicsComponent>		physicsComponents;
	std::vector<ActiveGraphicsComponent>	graphicsComponents;


	sf::FloatRect						mWorldBounds;
	int									tileSize;
};