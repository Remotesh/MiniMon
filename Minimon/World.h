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


class World : private sf::NonCopyable
{
public:
	explicit		World(sf::RenderWindow& window, CommandQueue& commands);
	void			update(sf::Time dt);
	void			draw();
	void			resolveCollision(GameObject*);
	Area*			getArea();
	std::string		getDebug();

private:
	void		loadTextures();

	void		addObject(GameObject, int, int);

	void		test();

	GameObject* createPlayer(sf::Texture* text)
	{
		return new GameObject(new PlayerCommandComponent(), new PlayerPhysicsComponent(), new PlayerGraphicsComponent(text));
	};

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
	Area*								mCurrentArea;
	Dungeon								mCurrentDungeon;

	//Removed Later
	sf::Sprite							grid;
	sf::Sprite*							woodlands = new sf::Sprite[10];
	sf::Clock							debugClock;

	std::ostringstream					mOss;
	std::string							mDebugInfo;

	std::map<const int, GameObject>			activeObjects;
	std::map<const int, GameObject>			inactiveObjects;


	sf::FloatRect						mWorldBounds;
	int									tileSize;
};