#pragma once

#include "SFML\Graphics.hpp"
#include "ResourceHolder.h"
#include "ResourceIdentifier.h"
#include "GameObject.h"
#include "Area.h"
#include "Dungeon.h"
#include <map>

class World : private sf::NonCopyable
{
public:
	explicit	World(sf::RenderWindow& window);
	void		update(sf::Time dt);
	void		draw();

private:
	void		loadTextures();
	void		resolveCollision();
	void		test();

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
	Area*								mCurrentArea;
	Dungeon								mCurrentDungeon;

	//Removed Later
	sf::Sprite							playerCharacter;
	sf::Sprite							grid;
	sf::Sprite*							woodlands = new sf::Sprite[10];

	std::map<int, GameObject>			activeObjects;
	std::map<int, GameObject>			inactiveObjects;

	sf::FloatRect						mWorldBounds;
	sf::Vector2f						mSpawnPosition;
	int									tileSize;
};