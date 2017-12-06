#pragma once

#include "ResourceHolder.h"
#include "SFML/Graphics.hpp"

namespace Textures
{
	enum ID
	{
		PlayerCharacter,
		Enemy,
		HealthPotion,
		Bomb,
		StoneTile,
		StoneWall,
		Grass,
	};
}

template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
