#pragma once
#include "SFML/Graphics.hpp"
#include "World.h"
#include "GameObject.h"

class PlayerCharacter : public GameObject
{
public:

	PlayerCharacter();

	int				x, y;
	sf::Vector2i	velocity;

	void Update(World& world);
};