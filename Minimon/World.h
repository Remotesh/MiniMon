#pragma once
#include "SFML\Graphics.hpp"
#include "ResourceHolder.h"
#include "ResourceIdentifier.h"

class World : private sf::NonCopyable
{
public:
	explicit	World(sf::RenderWindow& window);
	void		update(sf::Time dt);
	void		draw();

private:
	void		loadTextures();
	void		buildScene();

private:
	enum Layer {
		Tiles,
		Items,
		Objects,
		LayerCount
	};

private:
	sf::RenderWindow&					mWindow;
	sf::View							mWorldView;
	TextureHolder						mTextures;

	sf::FloatRect						mWorldBounds;
	sf::Vector2f						mSpawnPosition;
	int									tileSize;
};