#pragma once

#include <map>

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
	explicit	World(sf::RenderWindow& window, CommandQueue& commands);
	void		update(sf::Time dt);
	void		draw();

private:
	void		loadTextures();
	void		resolveCollision();
	void		test();

	GameObject* createPlayer()
	{
		return new GameObject(new PlayerCommandComponent(), new PlayerPhysicsComponent(), new PlayerGraphicsComponent());
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
	sf::Sprite							playerSprite;
	sf::Sprite							grid;
	sf::Sprite*							woodlands = new sf::Sprite[10];

	std::map<const int, GameObject>			activeObjects;
	std::map<const int, GameObject>			inactiveObjects;


	sf::FloatRect						mWorldBounds;
	sf::Vector2f						mSpawnPosition;
	int									tileSize;
};