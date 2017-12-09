#pragma once

#include "ResourceHolder.h"
#include "SFML/Graphics.hpp"

namespace Textures
{
	enum ID
	{
		Nothing,
		Grass,
		GrassWall,
		Dirt,
		StoneTile,
		StoneWall,
		PlayerCharacter,
		Enemy,
		Grid,
	};
}

template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
